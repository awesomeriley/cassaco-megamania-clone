/*************************************************************
 * Classe base para todas os objetos que representam uma nave
 * no jogo, todas as classes que s�o naves devem ter esta
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
	 * Construtor ~padr�o que cria um novo ator, informando 
	 * a anima��o do mesmo, a largura e altura de cada frame
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
	 * Fun��o responsavel por realizar a anima��o da morte do
	 * ator
	 *
	 *************************************************************/
	void Ship::Die(SDL_Surface *screen)
	{
	}

	/*************************************************************
	 * Fun��o responsavel por realizar a a��o de atirar
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
	 * Fun��o que seta o estado atual do ator
	 *
	 *************************************************************/
	void Ship::SetState(ShipState state)
	{
		this->state =  state;
	}

	/*************************************************************
	 * Fun��o responsavel por retornar o estado atual do ator
	 *
	 *************************************************************/
	void Ship::GetState(ShipState &state)
	{
		state = this->state;
	}

	/*************************************************************
	 * Fun��o responsavel por desenhar na tela todos os objetos
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
	 * Fun��o que retorna a referencia para a bala associada com 
	 * a nave
	 *
	 *************************************************************/
	Bullet & Ship::GetBullet(void) 
	{
		return *bullet;
	}

	/*************************************************************
	 * Fun��o responsavel por tratar os eventos relacionados com 
	 * a movimenta��o da nave
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
	 * Fun��o responsavel por resetar a posi��o da bala, a posi��o
	 * da bala sempre ser� setada no meio acima da nave
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
