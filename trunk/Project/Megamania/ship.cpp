/*************************************************************
 * Classe base para todas os objetos que representam uma nave
 * no jogo, todas as classes que são naves devem ter esta
 * classe como super-classe
 *
 * Author: Adriano Braga Alencar							
 * Email : adrianobragaalencar@gmail.com 
 *
 * Author : Marcelo Collyer
 * Email     : marcelocollyer@gmail.com
 *************************************************************/
#include "ship.h"
#include "game_config.h"

namespace Megamania
{

	/*************************************************************
	 * Construtor ~padrão que cria um novo ator, informando 
	 * a animação do mesmo, a largura e altura de cada frame
	 *
	 *************************************************************/
	Ship::Ship(const char *file, Uint16 frameWidth, Uint16 frameHeight)
	throw(SpriteException) : GameObject(file, frameWidth, frameHeight)
	{
		bullet = new Bullet();
		bullet->SetVisible(false);		
	}

	/*************************************************************
	 * Destruidor responsavel por desalocar todos os recursos
	 * alocados pelo ator
	 *
	 *************************************************************/
	Ship::~Ship(void)
	{
		delete bullet;
	}

	/*************************************************************
	 * Função responsavel por realizar a animação da morte do
	 * ator
	 *
	 *************************************************************/
	void Ship::Die(SDL_Surface *screen)
	{
	}

	/*************************************************************
	 * Função responsavel por realizar a ação de atirar
	 *
	 *************************************************************/
	void Ship::Shoot(void)
	{
		if(!bullet->IsVisible()) {
			bullet->SetVisible(true);
			ResetBulletPosition();
		}
	}

	/*************************************************************
	 * Função que seta o estado atual do ator
	 *
	 *************************************************************/
	void Ship::SetState(ShipState state)
	{
		this->state =  state;
	}

	/*************************************************************
	 * Função responsavel por retornar o estado atual do ator
	 *
	 *************************************************************/
	void Ship::GetState(ShipState &state)
	{
		state = this->state;
	}

	/*************************************************************
	 * Função responsavel por desenhar na tela todos os objetos
	 *
	 *************************************************************/
	void Ship::Draw(SDL_Surface *surface)
	{
		if(bullet->IsVisible()) {			
			bullet->Update(Megamania::Bullet::Direction::UP);
			bullet->Draw(surface);
		}
		GameObject::Draw(surface);
	}

	/*************************************************************
	 * Função que retorna a referencia para a bala associada com 
	 * a nave
	 *
	 *************************************************************/
	Bullet & Ship::GetBullet(void) 
	{
		return *bullet;
	}

	/*************************************************************
	 * Função responsavel por tratar os eventos relacionados com 
	 * a movimentação da nave
	 *
	 *************************************************************/
	void Ship::Event(SDL_Event *event)
	{
		int x = GetCurrentFrame();
		if(event->type == SDL_KEYDOWN) {
			switch(event->key.keysym.sym){
			
				case SDLK_LEFT:
					if(GetX() - MEGAMANIA_OFFSET > 0) {
						Move(-MEGAMANIA_OFFSET, 0);
						if(x > 0) {
							PrevFrame();
						} else {
							SetFrame(0);
						}
					}
					break;
				case SDLK_RIGHT:
					if(GetX() + GetWidthFrame() + MEGAMANIA_OFFSET < WIDTH_SCREEN) {
						Move(MEGAMANIA_OFFSET, 0);
						if(x < 3) {
							NextFrame();
						} else {
							SetFrame(3);
						}
					}
					break;
			}
		} else {
			SetFrame(2);
		}	
		if(SDL_GetKeyState(NULL)[SDLK_SPACE]) {
			Shoot();
		}
	}
	
	/*************************************************************
	 * Função responsavel por resetar a posição da bala, a posição
	 * da bala sempre será setada no meio acima da nave
	 *
	 *************************************************************/
	void Ship::ResetBulletPosition(void)
	{
		if(bullet->GetDirection() == bullet->UP){
			bullet->SetPosition(GetX() + (GetWidthFrame() >> 1), GetY() + GetHeightFrame());
		} else { 
			bullet->SetPosition(GetX() + (GetWidthFrame() >> 1), GetY());			
		}
	}
}
