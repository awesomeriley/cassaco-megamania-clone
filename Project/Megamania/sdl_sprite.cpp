/*****************************************************************
 * Classe que representa um Sprite, um Sprite nada mais é que
 * um elemento que pode ser renderizado e exibir diferentes 
 * frames de uma imagem informada, realizando assim uma animação
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ****************************************************************/
#include "sdl_sprite.h"
#include "megamania_utils.h"

namespace Megamania
{

	/***************************************************************
	 * Construtor padrão que cria um novo objeto Sprite
	 * associando o mesmo com a imagem fornecida pelo arquivo
	 * como parametro
	 * O construtor cria um objeto partindo a imagem nos
	 * parametros fornecidos para a largura e altura de cada
	 * frame
	 *
	 * file -> indica o caminho para a imagem que compoe o Sprite 
	 * frameWidth -> indica a largura para cada frame
	 * frameheight -> indica a altura para cada frame
	 * throw SpriteException -> exceção disparada caso o caminho para
	 * o arquivo seja NULL ou caso a largura ou a altura fornecida 
	 * não gere um sprite com um numero exato de frames
	 *
	 **************************************************************/
	Sprite::Sprite(const char *file, Uint32 frameWidth, Uint32 frameHeight)throw(SpriteException)
	{
		if(file == NULL) {
            throw SpriteException("O objeto Sprite não pode ser criado, [PATH NULL]");
		}
		this->image = LoadImage(file);
		int w = image->w;
		int h = image->h;
		if(((w % frameWidth) != 0)||((h % frameHeight) != 0)) {
			throw SpriteException("A imagem fornecida não é válida para o Sprite");
		}		
		this->frameWidth = frameWidth;
		this->frameHeight = frameHeight;
		this->nFrames = static_cast<Uint32>((w / frameWidth) * (h / frameHeight)); 
		CreateFrames();
        x = y = 0;
	}

	/***************************************************************
	 * Função destruidora responsavel por desalocar todos
	 * os recursos alocados pelo objeto Sprite
	 *
	 **************************************************************/
	Sprite::~Sprite(void) 
	{	
		SDL_FreeSurface(image);
		for(int i = frames.size(); --i >= 0;) {
			delete frames[i];
		}
	}

	void Sprite::CreateFrames(void) 
	{
		int x = 0;
		int y = 0;
		int w = image->w;
		int maxFrameWidth = (w / frameWidth);
		for(Uint32 i = 0; i < nFrames; ++i) {
			SDL_Rect rect;
			rect.x = (i * frameWidth) % w;
			rect.y = (i / maxFrameWidth) * frameHeight;
			rect.w = frameWidth;
			rect.h = frameHeight;
			frames.push_back(&rect);
		}
	}
    
	/***************************************************************
	 * Função que move o cursor responsavel por indicar a
	 * posição atual no Sprite para o próximo FRAME, caso 
	 * o final da animação seja alcançado, o cursor passará
	 * a apontar para o inicio da animação
	 *
	 **************************************************************/
	void Sprite::NextFrame(void) 
	{
		if(cursor < nFrames - 1) {
			++cursor;
		} else {
		    cursor = 0;
		}
	}

	/***************************************************************
	 * Função que move o cursor responsavel por indicar a
	 * posição atual no Sprite para o FRAME anterior, caso 
	 * o inicio da animação seja alcançado, o cursor passará
	 * a apontar para o final da animação
	 *
	 **************************************************************/
	void Sprite::PrevFrame(void) 
	{	
		if(cursor > 0) {
		    --cursor;
		} else {
		    cursor = nFrames - 1;
		}
	}

	/***************************************************************
	 * Função que seta a posição do objeto Sprite
	 * na coordenada X
	 *
	 * x -> indica a posição do Sprite no eixo X 
	 *
	 **************************************************************/
	void Sprite::SetX(int x) 
	{	
		this->x = x;
	}
	
	/***************************************************************
	 * Função que seta a posição do objeto Sprite
	 * na coordenada Y
	 *
	 * y -> indica a posição do Sprite no eixo Y
	 *
	 **************************************************************/
	void Sprite::SetY(int y) 
	{
		this->y = y;
	}

	/***************************************************************
	 * Função que retorna a posição do objeto Sprite
	 * na coordenada X
	 *
	 * int -> indica a posição do Sprite no eixo X 
	 *
	 **************************************************************/
	const int Sprite::GetX(void)const
	{	
		return this->x;
	}
	
	/***************************************************************
	 * Função que retorna a posição do objeto Sprite
	 * na coordenada Y
	 *
	 * int -> indica a posição do Sprite no eixo Y
	 *
	 **************************************************************/
	const int Sprite::GetY(void)const
	{
		return this->y;
	}

	/***************************************************************
	 * Função que seta a posição do objeto Sprite
	 *
	 * x -> indica a nova posição no eixo X
	 * y -> indica a nova posição no eixo Y
	 *
	 **************************************************************/
	void Sprite::SetPosition(int x, int y) 
	{
		SetX(x);
		SetY(y);
	}

	/*****************************************************************
	 * Função que retorna a posição atual do objeto Sprite
	 * inserido os valores dos eixos X e Y nas referencias
	 * informadas
	 * 
	 * xRef -> referencia para o eixo X
	 * yRef -> referencia para o eixo Y
	 *
	 */
	void Sprite::GetPosition(int &xRef, int &yRef) 
	{
		xRef = x;
		yRef = y;
	}

	/****************************************************************
	 * Função responsavel por realizar um deslocamento na posição 
	 * do objeto Sprite pelo valor fornecido por exemplo:
	 *
	 * Sprite *sprite = new Sprite();
	 * sprite->SetX(10);
	 * sprite->SetY(10);
	 * 
	 * std::cout<<"Posição X"<<sprite->GetX();    //imprime 10
	 * std::cout<<"Posição X"<<sprite->GetY();    //imprime 10
	 *
	 * sprite->Move(10, -10);
	 *
	 * std::cout<<"Posição X"<<sprite->GetX();    //imprime agora 20
	 * std::cout<<"Posição X"<<sprite->GetY();    //imprime agora 0
	 *
	 ****************************************************************/
	void Sprite::Move(int dx, int dy) 
	{
		this->x += dx;
		this->y += dy;
	}

	/***************************************************************
	 * Função que retorna o valor indicando a largura
	 * de cada frame do objeto Sprite
	 *
	 * int -> indica a largura de cada frame
	 *
	 **************************************************************/
	const int Sprite::GetWidthFrame(void)const 
	{	
		return this->frameWidth;
	}

	/***************************************************************
	 * Função que retorna o valor indicando a altura
	 * de cada frame do objeto Sprite
	 *
	 * int -> indica a altura de cada frame
	 *
	 **************************************************************/
	const int Sprite::GetHeightFrame(void)const 
	{
		return this->frameHeight;
	}

	/***************************************************************
	 * Função que retorna o valor indicando a quantidade
	 * total de frames do objeto Sprite
	 *
	 * int -> indica a quantidade de frames do objeto
	 * Sprite
	 *
	 **************************************************************/
	const int Sprite::GetFrameNumbers(void)const
	{
		return this->nFrames;
	}

	bool Sprite::CollidesWith(Sprite &another)
	{
		return false;
	}
	

	/***************************************************************
	 * Função responsavel por realizar a pintura do Sprite na tela
	 * esta função irá pintar o Frame corrente setado pelo usuário
	 *
	 * SDL_Surface -> indica a superficie que irá receber a pintura
	 * do Frame do Sprite
	 ***************************************************************/
	void Sprite::Draw(SDL_Surface *surface)
	{
		if(surface != NULL) {
		    
			SDL_Rect rect;
			rect.x = GetX(); 
			rect.y = GetY();
			SDL_BlitSurface(image, frames[cursor], surface, &rect);
		}
	}
}
