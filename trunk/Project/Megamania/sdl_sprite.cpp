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
	Sprite::Sprite(const char *file, Uint16 frameWidth, Uint16 frameHeight)throw(SpriteException)
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
		this->nFrames = static_cast<Uint16>((w / frameWidth) * (h / frameHeight)); 
		CreateFrames();
        cursor = x = y = 0;
		SetVisible(true);
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
			SDL_free(frames[i]);
		}
		frames.clear();
	}

	/*************************************************************
	 * Função responsavel por criar os frames do objeto Sprite
	 * baseado na largura e altura informadas
	 *
	 *************************************************************/
	void Sprite::CreateFrames(void) 
	{
		int x = 0;
		int y = 0;
		int w = image->w;
		int maxFrameWidth = (w / frameWidth);
		SDL_Rect *rect = NULL;
		for(Uint32 i = 0; i < nFrames; ++i) {
			rect = reinterpret_cast<SDL_Rect *>(SDL_malloc(sizeof(SDL_Rect)));
			rect->x = (i * frameWidth) % w;
			rect->y = (i / maxFrameWidth) * frameHeight;
			rect->w = frameWidth;
			rect->h = frameHeight;
			frames.push_back(rect);
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
		cursor = cursor < nFrames - 1 ? ++cursor : 0;
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
		cursor = cursor > 0 ? --cursor : nFrames - 1;
	}

	/*************************************************************
	 * Função que retorna o índice do frame corrente, o índice 
	 * retornado deverá esta entre a faixa de [0,  (n - 1)] onde
	 * n indica a quantidade de frames do Sprite
	 * 
	 *************************************************************/
	int Sprite::GetCurrentFrame(void)
	{
		return cursor;
	}
	
	/*************************************************************
	 * Função que seta como frame corrente o referente ao índice
	 * informado, caso seja informado um índice que não esteja 
	 * na seguinte faixa [0, (n - 1)] ocorrerá um erro de acesso
	 * além dos limites do std::vector<SDL_Rect*>
	 *
	 *************************************************************/
	void Sprite::SetFrame(int frameIndex){
	
		if((frameIndex >= 0)&&(frameIndex < nFrames)){
			cursor = frameIndex;
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

	/******************************************************************
	 * Função responsavel por testar a colisão entre dois objetos 
	 * Sprites, o algoritmo aplicado para o teste de colisão é muito
	 * simples é o algoritmo de colisão por retangulo que testa
	 * somente se dois retangulos se sobrepoem, segue abaixo um 
	 * exemplo do funcionamento do algoritmo:
	 *    x1        w1
	 * y1 +----------+
	 *    |       x2 |      w2
	 *    |    y2 +----------+
	 *    |       |  |       |
	 * h1 +-------|--+       |
	 *		      |          |
	 *		   h2 +----------+
	 *
	 * Se x1 + w1 > w2 && y1 + h1 > y2 && x1 < x2 + w2 && y1 < y2 + h2
	 * indica que ocorreu uma colisão pois em algum ponto os retangulos
	 * se sobrepoem
	 *
	 *******************************************************************/
	bool Sprite::CollidesWith(Sprite &another)
	{
		int x1 = (*this).x;    
		int y1 = (*this).y;    
		int w1 = (*this).frameWidth;     
		int h1 = (*this).frameWidth;     

		int x2 = another.x;    
		int y2 = another.y;    
		int w2 = another.frameWidth;
		int h2 = another.frameHeight;

		return (x1 < x2 + w2)&&(y1 < y2 + h2)&&(x2 < x1 + w1)&&(y2 < y1 + h1);
	}
	
	/***************************************************************
	 * Função que retorna o valor indicando se o Sprite atual esta
	 * ou não visivel
	 *
	 ***************************************************************/
	bool Sprite::IsVisible(void) 
	{
		return visible;
	}

	/***************************************************************
	 * Função que seta a visibilidade do Sprite atual 
	 *
	 ***************************************************************/
	void Sprite::SetVisible(bool visible)
	{
		this->visible = visible;
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
		if((surface != NULL)&&(IsVisible())) {
		    
			SDL_Rect rect;
			rect.x = GetX(); 
			rect.y = GetY();
			SDL_BlitSurface(image, frames[cursor], surface, &rect);
		}
	}
}
