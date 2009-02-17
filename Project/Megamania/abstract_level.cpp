/***************************************************************
 * Classe que representa a classe base para todas as fases 
 * do jogo, toda fase deverá herdar diretamente desta classe
 *
 * Author Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ***************************************************************/
#include "abstract_level.h"
#include "user_event_type.h"
#include "game_controller.h"

/** objeto global para o tratamento de eventos*/
extern SDL_Event event;

namespace Megamania
{
	/***************************************************************
	 * Construtor default que cria um novo objeto AbstractLevel
	 * associando o mesmo com a Tela da aplicação
	 *
	 * SDL_Surface *screen -> indica a tela do jogo
	 * 
	 **************************************************************/
	AbstractLevel::AbstractLevel(SDL_Surface *screen)throw(SDLVideoException) : AbstractScreen(screen)
	{   
		hud = HUD::GetInstance();
		lastTimer = SDL_GetTicks();
		timerAcum = currentTimer = 0;
	}

	/***************************************************************
	 * Função que seta a referencia para a nave principal
	 * 
	 **************************************************************/
	void AbstractLevel::SetMegamania(Ship *megamania)
	{
		this->megamania = megamania;		
		megamania->SetVisible(true);
	}

	/***************************************************************
	 * Função que seta a quantidade de naves por fase
	 * 
	 **************************************************************/
	void AbstractLevel::SetShipCount(Uint16 shipCount)
	{
		this->shipCount = shipCount;
	}

	/***************************************************************
	 * Função responsavel por iniciar a posição de todas as naves
	 * inimigas e tambem a posição da nave Megamania
	 *
	 **************************************************************/
	void AbstractLevel::Init() 
	{
		megamania->SetPosition(WIDTH_SCREEN >> 1, hud->GetRect().y - megamania->GetHeightFrame());
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
	 * Função que representa o ponto de entrada para a execução da 
	 * fase
	 *
	 **************************************************************/
	void AbstractLevel::Execute(void) 
	{
		Draw();
	}

	/***************************************************************
	 * Função de callback chamada pelo gerenciador de eventos, esta
	 * função representa o ponto de entrada para o tratamento da 
	 * da lógica da classe	
	 *
	 **************************************************************/
	void AbstractLevel::Event(SDL_Event *event) 
	{
		megamania->Event(event);
	}

	/***************************************************************
	 * Função responsavel por repintar toda a tela
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
					if(enemyBullet->IsVisible() && megamania->IsVisible() && megamania->CollidesWith(*enemyBullet)){
						megamania->SetVisible(false);
						hud->DecrementLife();
						enemyBullet->SetVisible(false);				
						FinishLevel();
					}
					if((bullet.IsVisible())&&(enemy->CollidesWith(bullet))) {
						enemy->SetVisible(false);
						bullet.SetVisible(false);
						hud->IncrementPoint(enemy->GetPointValue());
					}
				} else if(enemyBullet->IsVisible()) {
					enemyBullet->Draw(screen);
					enemyBullet->Update(Megamania::Bullet::Direction::DOWN);
				}
			}	
			
			if(!hasEnemyAlive){
				levelComplete = 1;		
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

	/** Finaliza o level */
	void AbstractLevel::FinishLevel(void){
		
		event.type = SDL_USEREVENT;
		event.user.code = levelFinishEvent;
		event.user.data1 = &levelComplete;
		SDL_PushEvent(&event);
	}

	/***************************************************************
	 * Função responsavel por desalocar todos os recursos alocados
	 * pela tela, esta funçao deverá ser chamada por ultimo
	 *
	 **************************************************************/
	void AbstractLevel::Clear(void) 
	{
		for(Uint32 i = 0; i < LEVEL_1_NUMBER_SHIPS; ++i) {
			delete enemies[i];
		}
		enemies.clear();
	}
}