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

/** Macro definida somente para uso interno da classe*/
#define CHECK_LIFE(o)   o->GetLife() <= 0     
#define Restart RestartLevel


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
		enemies.reserve(BLOCK_MEMORY_RESERVE);
		bullets.reserve(BLOCK_MEMORY_RESERVE);
		hud = HUD::GetInstance();
		lastTimer = SDL_GetTicks();
		timerAcum = currentTimer = 0;
		levelComplete = false;
	}

	/***************************************************************
	 * Função que seta a referencia para a nave principal
	 * 
	 **************************************************************/
	void AbstractLevel::SetMegamania(Ship *megamania)
	{
		this->megamania = megamania;				
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
		bulletCount = 0;
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
			int x = 0xffffffff;
			int y = 0xffffffff;			
			for(Uint32 i = 0; i < shipCount; ++i) {
				enemy = dynamic_cast<Enemy *>(enemies[i]);
				enemyBullet = &enemy->GetBullet();
				x = enemy->GetX();
				y = enemy->GetY();
				if(enemy->IsVisible()) {
					hasEnemyAlive = true;
					if((i == randomShootShipNumber)&&(!enemyBullet->IsVisible())) {						
						if((bulletCount < MAX_BULLET)&&(x > 0)&&(x + enemy->GetWidthFrame() < WIDTH_SCREEN)
							&&(y > 0)&&(y + enemy->GetHeightFrame() < HEIGHT_SCREEN)) {
							enemy->Shoot();
							++bulletCount;
							bullets.push_back(enemyBullet);
						}												
					}
					enemy->Draw(screen);
					enemy->NextFrame();
					enemy->Update();					
					if(enemyBullet->IsVisible() && megamania->IsVisible() && enemyBullet->CollidesWith(*megamania)){
						enemyBullet->SetVisible(false);							
						Restart();
						break;						
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
				for(int i = 0, len = bullets.size(); i < len; ++i) {
					enemyBullet = bullets[i];
					if((enemyBullet != NULL)&&(!enemyBullet->IsVisible())) {
						--bulletCount;
						bullets.erase(std::find(bullets.begin(), bullets.end(), enemyBullet));
						--len;
					}
				}
			}	
			
			if(!hasEnemyAlive){
				levelComplete = true;	
				hud->Empty();
				megamania->GetBullet().SetVisible(false);
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
				Restart();						
			}
			timerAcum = 0;
		}		
		megamania->Draw(screen);
		SDL_Flip(screen);
	}

	/***************************************************************
	 * Função que insere um evento indicando que o level atual deve
	 * ser reiniciado, pois o jogador morreu
	 *
	 **************************************************************/
	void AbstractLevel::RestartLevel(void) 
	{
		megamania->SetVisible(false);												
		if(CHECK_LIFE(hud)) {
			hud->Reset();
			event.type = SDL_USEREVENT;
			event.user.code = GAME_OVER;
			SDL_PushEvent(&event);
			return;
		}
		hud->DecrementLife();												
		bulletCount = 0;
		bullets.clear();
		megamania->Die(screen);
		Init();
	}

	/***************************************************************
	 * Função que insere um evento indicando que o level atual foi
	 * finalizado e que se deve começar uma nova fase
	 *
	 **************************************************************/
	void AbstractLevel::FinishLevel(void){
		
		event.type = SDL_USEREVENT;
		event.user.code = levelFinishEvent;
		SDL_PushEvent(&event);
	}

	/***************************************************************
	 * Função responsavel por desalocar todos os recursos alocados
	 * pela tela, esta funçao deverá ser chamada por ultimo
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