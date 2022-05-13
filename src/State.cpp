#define INCLUDE_SDL

#include "../inc/SDL_include.h"
#include "../inc/State.h"
#include "../inc/Sound.h"
#include "../inc/Face.h"
#include "../inc/TileMap.h"
#include "../inc/InputManager.h"

#define PI 3.14159265

#define TILE_WIDTH  64
#define TILE_HEIGHT 64

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

  /* Cria e adiciona TileMap */
  GameObject* map = new GameObject();
  TileSet* tileSet = new TileSet(TILE_WIDTH, TILE_HEIGHT, "assets/img/tileset.png");
  TileMap* tileMap = new TileMap(*map, "assets/map/tileMap.txt", tileSet);
  map->AddComponent(tileMap);

  /* Atribui posicao */
  map->box.x = 0;
  map->box.y = 0;

  /* Insere GameObject no arrayObjects */
  this->objectArray.emplace_back(map);

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
  InputManager& input = InputManager::GetInstance();
  /* Verifica se termino do jogo foi solicitado */
  if (input.QuitRequested() || input.KeyPress(ESCAPE_KEY)) 
    this->quitRequested = true;
  /* Cria novo objeto com pressionar da tecla espaco */
  if (input.KeyPress(SPACE_KEY)) {
    Vec2 objPos = Vec2(200, 0).Rotate(-PI + PI*(std::rand() % 1001)/500.0) + Vec2(input.GetMouseX(), input.GetMouseY());
    this->AddObject((int) objPos.x, (int) objPos.y);
  }
  
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