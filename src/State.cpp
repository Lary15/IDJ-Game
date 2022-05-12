#define INCLUDE_SDL

#include "../inc/SDL_include.h"
#include "../inc/State.h"
#include "../inc/Sound.h"
#include "../inc/Face.h"

#define PI 3.14159265

/* Construtor */
State::State() : bg(*new GameObject)
{
  this->quitRequested = false;

  /* Adiciona componente sprite */
  GameObject* background = new GameObject();
  background->AddComponent(&(this->bg));
  
  /* Atribui posicao */
  background->box.x = 0;
  background->box.y = 0;

  /* Insere GameObject no arrayObjects */
  this->objectArray.emplace_back(background);

  /* Instanciar Sprite e Music */
  this->LoadAssets();
  this->music.Play(); /* Temporario - apenas para testar musica */
}

State::~State() {
  this->objectArray.clear();
}

void State::LoadAssets()
{
  /* Pre-carrega os assets */
  this->bg.Open("assets/img/ocean.jpg");
  this->music.Open("assets/audio/stageState.ogg");
}

void State::Update(float dt)
{
  this->Input();
  
  for (unsigned int i=0; i<this->objectArray.size(); i++) {
    this->objectArray[i]->Update(dt);
    /* Remove objetos mortos*/
    if (this->objectArray[i]->IsDead()) {
      this->objectArray.erase(this->objectArray.begin()+i);
    }
  }
}

void State::Render() {
  for (unsigned int i=0; i<this->objectArray.size(); i++) {
    this->objectArray[i]->Render();
  }
}

bool State::QuitRequested() {
  return this->quitRequested;
}

void State::AddObject(int mouseX, int mouseY) {
  /* Cria GameObject referente ao inimigo (penguim) */
  GameObject* penguin = new GameObject();

  /* Cria e adiciona componente sprite */
  Sprite* sprite = new Sprite(*penguin, "assets/img/penguinface.png");
  penguin->AddComponent(sprite);

  /* Atribui posicao da box */
  penguin->box.x = mouseX + penguin->box.w/2;
  penguin->box.y = mouseY + penguin->box.h/2;
  
  /*Cria e adiciona componente sound */
  Sound* sound = new Sound(*penguin, "assets/audio/boom.wav");
  penguin->AddComponent(sound);

  /*Cria e adiciona componente face */
  Face* face = new Face(*penguin);
  penguin->AddComponent(face);

  /* Insere GameObject no arrayObjects*/
  this->objectArray.emplace_back(penguin);
}

void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para terminação
		if(event.type == SDL_QUIT) {
			quitRequested = true;
		}
		
		// Se o evento for clique...
		if(event.type == SDL_MOUSEBUTTONDOWN) {

			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for(int i = objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*) objectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

				if (go->box.Contains({ (float)mouseX, (float)mouseY})) {
					Face* face = (Face*) go->GetComponent("Face");
					if ( nullptr != face ) {
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (só queremos acertar um)
						break;
					}
				}
			}
		}
		if ( event.type == SDL_KEYDOWN ) {
			// Se a tecla for ESC, setar a flag de quit
			if( event.key.keysym.sym == SDLK_ESCAPE ) {
				quitRequested = true;
			}
			// Se não, crie um objeto
			else {
				Vec2 objPos = Vec2(200, 0).Rotate(-PI + PI*(std::rand() % 1001)/500.0) + Vec2(mouseX, mouseY);
				this->AddObject((int) objPos.x, (int) objPos.y);
			}
		}
	}
}