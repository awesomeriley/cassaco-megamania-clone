/*****************************************************************
 * Classe que representa um Sprite, um Sprite nada mais � que
 * um elemento que pode ser renderizado e exibir diferentes 
 * frames de uma imagem informada, realizando assim uma anima��o
 *
 * Author: Adriano Braga Alencar (adrianobragaalencar@gmail.com) 
 *
 ****************************************************************/
#include "sdl_sprite.h"
#include "megamania_utils.h"

namespace Megamania
{

	/***************************************************************
	 * Construtor padr�o que cria um novo objeto Sprite
	 * associando o mesmo com a imagem fornecida pelo arquivo
	 * como parametro
	 * O construtor cria um objeto partindo a imagem nos
	 * parametros fornecidos para a largura e altura de cada
	 * frame
	 *
	 * file -> indica o caminho para a imagem que compoe o Sprite 
	 * frameWidth -> indica a largura para cada frame
	 * frameheight -> indica a altura para cada frame
	 * throw SpriteException -> exce��o disparada caso o caminho para
	 * o arquivo seja NULL ou caso a largura ou a altura fornecida 
	 * n�o gere um sprite com um numero exato de frames
	 *
	 **************************************************************/
	Sprite::Sprite(const char *file, Uint16 frameWidth, Uint16 frameHeight)throw(SpriteException)
	{
		if(file == NULL) {
            throw SpriteException("O objeto Sprite n�o pode ser criado, [PATH NULL]");
		}
		this->frames.reserve(BLOCK_MEMORY_RESERVE);    //evita o overhead de c�pia dos dados a cada inser��o
		this->image = LoadImage(file);
		int w = image->w;
		int h = image->h;
		if(((w % frameWidth) != 0)||((h % frameHeight) != 0)) {
			throw SpriteException("A imagem fornecida n�o � v�lida para o Sprite");
		}		
		this->frameWidth = frameWidth;
		this->frameHeight = frameHeight;
		this->nFrames = static_cast<Uint16>((w / frameWidth) * (h / frameHeight)); 
		CreateFrames();
        cursor = x = y = 0;
		SetVisible(true);
	}

	/***************************************************************
	 * Fun��o destruidora responsavel por desalocar todos
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
	 * Fun��o responsavel por criar os frames do objeto Sprite
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
	 * Fun��o que move o cursor responsavel por indicar a
	 * posi��o atual no Sprite para o pr�ximo FRAME, caso 
	 * o final da anima��o seja alcan�ado, o cursor passar�
	 * a apontar para o inicio da anima��o
	 *
	 **************************************************************/
	void Sprite::NextFrame(void) 
	{
		cursor = cursor < nFrames - 1 ? ++cursor : 0;
	}

	/***************************************************************
	 * Fun��o que move o cursor responsavel por indicar a
	 * posi��o atual no Sprite para o FRAME anterior, caso 
	 * o inicio da anima��o seja alcan�ado, o cursor passar�
	 * a apontar para o final da anima��o
	 *
	 **************************************************************/
	void Sprite::PrevFrame(void) 
	{	
		cursor = cursor > 0 ? --cursor : nFrames - 1;
	}

	/*************************************************************
	 * Fun��o que retorna o �ndice do frame corrente, o �ndice 
	 * retornado dever� esta entre a faixa de [0,  (n - 1)] onde
	 * n indica a quantidade de frames do Sprite
	 * 
	 *************************************************************/
	int Sprite::GetCurrentFrame(void)
	{
		return cursor;
	}
	
	/*************************************************************
	 * Fun��o que seta como frame corrente o referente ao �ndice
	 * informado, caso seja informado um �ndice que n�o esteja 
	 * na seguinte faixa [0, (n - 1)] ocorrer� um erro de acesso
	 * al�m dos limites do std::vector<SDL_Rect*>
	 *
	 *************************************************************/
	void Sprite::SetFrame(int frameIndex){
	
		if((frameIndex >= 0)&&(frameIndex < nFrames)){
			cursor = frameIndex;
		}
	}

	/***************************************************************
	 * Fun��o que seta a posi��o do objeto Sprite
	 * na coordenada X
	 *
	 * x -> indica a posi��o do Sprite no eixo X 
	 *
	 **************************************************************/
	void Sprite::SetX(int x) 
	{	
		this->x = x;
	}
	
	/***************************************************************
	 * Fun��o que seta a posi��o do objeto Sprite
	 * na coordenada Y
	 *
	 * y -> indica a posi��o do Sprite no eixo Y
	 *
	 **************************************************************/
	void Sprite::SetY(int y) 
	{
		this->y = y;
	}

	/***************************************************************
	 * Fun��o que retorna a posi��o do objeto Sprite
	 * na coordenada X
	 *
	 * int -> indica a posi��o do Sprite no eixo X 
	 *
	 **************************************************************/
	const int Sprite::GetX(void)const
	{	
		return this->x;
	}
	
	/***************************************************************
	 * Fun��o que retorna a posi��o do objeto Sprite
	 * na coordenada Y
	 *
	 * int -> indica a posi��o do Sprite no eixo Y
	 *
	 **************************************************************/
	const int Sprite::GetY(void)const
	{
		return this->y;
	}

	/***************************************************************
	 * Fun��o que seta a posi��o do objeto Sprite
	 *
	 * x -> indica a nova posi��o no eixo X
	 * y -> indica a nova posi��o no eixo Y
	 *
	 **************************************************************/
	void Sprite::SetPosition(int x, int y) 
	{
		SetX(x);
		SetY(y);
	}

	/*****************************************************************
	 * Fun��o que retorna a posi��o atual do objeto Sprite
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
	 * Fun��o responsavel por realizar um deslocamento na posi��o 
	 * do objeto Sprite pelo valor fornecido por exemplo:
	 *
	 * Sprite *sprite = new Sprite();
	 * sprite->SetX(10);
	 * sprite->SetY(10);
	 * 
	 * std::cout<<"Posi��o X"<<sprite->GetX();    //imprime 10
	 * std::cout<<"Posi��o X"<<sprite->GetY();    //imprime 10
	 *
	 * sprite->Move(10, -10);
	 *
	 * std::cout<<"Posi��o X"<<sprite->GetX();    //imprime agora 20
	 * std::cout<<"Posi��o X"<<sprite->GetY();    //imprime agora 0
	 *
	 ****************************************************************/
	void Sprite::Move(int dx, int dy) 
	{
		this->x += dx;
		this->y += dy;
	}

	/***************************************************************
	 * Fun��o que retorna o valor indicando a largura
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
	 * Fun��o que retorna o valor indicando a altura
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
	 * Fun��o que retorna o valor indicando a quantidade
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
	 * Fun��o responsavel por testar a colis�o entre dois objetos 
	 * Sprites, o algoritmo aplicado para o teste de colis�o � muito
	 * simples � o algoritmo de colis�o por retangulo que testa
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
	 * indica que ocorreu uma colis�o pois em algum ponto os retangulos
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
	 * Fun��o que retorna o valor indicando se o Sprite atual esta
	 * ou n�o visivel
	 *
	 ***************************************************************/
	bool Sprite::IsVisible(void) 
	{
		return visible;
	}

	/***************************************************************
	 * Fun��o que seta a visibilidade do Sprite atual 
	 *
	 ***************************************************************/
	void Sprite::SetVisible(bool visible)
	{
		this->visible = visible;
	}

	/***************************************************************
	 * Fun��o responsavel por realizar a pintura do Sprite na tela
	 * esta fun��o ir� pintar o Frame corrente setado pelo usu�rio
	 *
	 * SDL_Surface -> indica a superficie que ir� receber a pintura
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
