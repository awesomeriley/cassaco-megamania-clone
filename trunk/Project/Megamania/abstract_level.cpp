/***************************************************************
 * Classe que representa a classe base para todas as fases 
 * do jogo, toda fase dever� herdar diretamente desta classe
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ***************************************************************/
#include "abstract_level.h"
#include "user_event_type.h"
#include "game_controller.h"

/** objeto global para o tratamento de eventos*/
extern SDL_Event event;

/** Macro definida somente para uso interno da classe*/
#define CHECK_LIFE(o)   o->GetLife() < 0            


namespace Megamania
{
	/***************************************************************
	 * Construtor default que cria um novo objeto AbstractLevel
	 * associando o mesmo com a Tela da aplica��o
	 *
	 * SDL_Surface *screen -> indica a tela do jogo
	 * 
	 **************************************************************/
	AbstractLevel::AbstractLevel(SDL_Surface *screen)throw(SDLVideoException) : AbstractScreen(screen)
	{   
		hud = HUD::GetInstance();
		lastTimer = SDL_GetTicks();
		timerAcum = currentTimer = 0;
		levelComplete = false;
	}

	/***************************************************************
	 * Fun��o que seta a referencia para a nave principal
	 * 
	 **************************************************************/
	void AbstractLevel::SetMegamania(Ship *megamania)
	{
		this->megamania = megamania;				
	}

	/***************************************************************
	 * Fun��o que seta a quantidade de naves por fase
	 * 
	 **************************************************************/
	void AbstractLevel::SetShipCount(Uint16 shipCount)
	{
		this->shipCount = shipCount;
	}

	/***************************************************************
	 * Fun��o responsavel por iniciar a posi��o de todas as naves
	 * inimigas e tambem a posi��o da nave Megamania
	 *
	 **************************************************************/
	void AbstractLevel::Init() 
	{
		megamania->SetPosition(WIDTH_SCREEN >> 1, hud->GetRect().y - megamania->GetHeightFrame());		
		megamania->SetVisible(true);
		megamania->SetFrame(2);				
		Draw();
		hud->Full();		
	}

	/***************************************************************
	 * Destruidor responsavel por desalocar todos os recursos
	 * alocados pela classe
	 *
	 **************************************************************/
	AbstractLevel::~AbstractLevel() 
	{    
		Clear();
	}

	/***************************************************************
	 * Fun��o que representa o ponto de entrada para a execu��o da 
	 * fase
	 *
	 **************************************************************/
	void AbstractLevel::Execute(void) 
	{
		Draw();
	}

	/***************************************************************
	 * Fun��o de callback chamada pelo gerenciador de eventos, esta
	 * fun��o representa o ponto de entrada para o tratamento da 
	 * da l�gica da classe	
	 *
	 **************************************************************/
	void AbstractLevel::Event(SDL_Event *event) 
	{
		megamania->Event(event);
	}

	/***************************************************************
	 * Fun��o responsavel por repintar toda a tela
	 *
	 **************************************************************/	
	void AbstractLevel::Draw(void) 
	{	
		if(!levelComplete){
			bool hasEnemyAlive = false;
			Enemy *enemy= NULL;
			int randomShootShipNumber = 1 + rand() % shipCount;
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
			Bullet &bullet = megamania->GetBullet();
			Bullet *enemyBullet = NULL;			
			for(Uint32 i = 0; i < shipCount; ++i) {
				enemy = dynamic_cast<Enemy *>(enemies[i]);
				enemyBullet = &enemy->GetBullet();
				if(enemy->IsVisible()) {
					hasEnemyAlive = true;
					if((i == randomShootShipNumber)&&(!enemy->GetBullet().IsVisible())){
						enemy->Shoot();
					}		
					enemy->Draw(screen);
					enemy->NextFrame();
					enemy->Update();					
					if(enemyBullet->IsVisible() && megamania->IsVisible() && enemyBullet->CollidesWith(*megamania)){
						enemyBullet->SetVisible(false);							
						megamania->SetVisible(false);												
						hud->DecrementLife();												
						if(CHECK_LIFE(hud)) {
						}
						FinishLevel();
					}
					if((bullet.IsVisible())&&(bullet.CollidesWith(*enemy))) {						
						bullet.SetVisible(false);
						enemy->SetVisible(false);
						hud->IncrementPoint(enemy->GetPointValue());
					}
				} else if(enemyBullet->IsVisible()) {
					enemyBullet->Draw(screen);
					enemyBullet->Update(Megamania::Bullet::Direction::DOWN);					
				}
			}	
			
			if(!hasEnemyAlive){
				levelComplete = true;	
				hud->Empty();
				FinishLevel();
			}
		}		
		currentTimer = SDL_GetTicks();
		if(currentTimer >= lastTimer) {
			timerAcum += (currentTimer - lastTimer);
		} 
		lastTimer = currentTimer;
		if(timerAcum >= DELAY) {
			if(hud->Draw()) {
				megamania->Die(screen);								
			}
			timerAcum = 0;
		}		
		megamania->Draw(screen);
		SDL_Flip(screen);
	}

	/***************************************************************
	 * Fun��o que insere um evento indicando que o level atual foi
	 * finalizado e que se deve come�ar uma nova fase
	 *
	 **************************************************************/
	void AbstractLevel::FinishLevel(void){
		
		event.type = SDL_USEREVENT;
		event.user.code = levelFinishEvent;
		SDL_PushEvent(&event);
	}

	/***************************************************************
	 * Fun��o responsavel por desalocar todos os recursos alocados
	 * pela tela, esta fun�ao dever� ser chamada por ultimo
	 *
	 **************************************************************/
	void AbstractLevel::Clear(void) 
	{
		for(Uint32 i = 0; i < shipCount; ++i) {
			delete enemies[i];
		}
		enemies.clear();
	}
}