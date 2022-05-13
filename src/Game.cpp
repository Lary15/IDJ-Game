#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

#include "../inc/SDL_include.h"
#include "../inc/Game.h"
#include "../inc/Resources.h"
#include "../inc/InputManager.h"

#include <stdexcept>
#include <cstdlib>
#include <ctime>

/* Para funcao Mix_OpenAudio */
#define MIX_DEFAULT_CHUNKSIZE 1024

/* Inicializando variavel static */
Game* Game::instance;

/* Inicializador Singleton */
Game& Game::GetInstance()
{
  if (instance == nullptr)
    instance = new Game("Larissa - 180021702", 1024, 600);

  return *instance;
}

/* Construtor */
Game::Game(std::string title, int width, int height)
{
  if (instance != nullptr)
    throw std::runtime_error("Game being initialized multiple times!");
  else
    instance = this;
  
  /* Inicializa seed do rand */
  srand(time(NULL));

  /* Inicializando biblioteca SLD e auxiliares */
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER))
  {
    SDL_Log("Unable to initialize SDL: %s\n", SDL_GetError());
    exit(1); /* Em caso de erro na inicializacao do SDL, encerre a execucao */
  }

  int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
  /* Inicializando biblioteca de imagem */
  if ((imgFlags & IMG_Init(imgFlags)) != imgFlags)
    SDL_Log("Unable to initialize image loader: %s\n", IMG_GetError());

  int mixFlags = MIX_INIT_OGG;
  /* Inicializando decoders da biblioteca de som */
  if ((mixFlags & Mix_Init(mixFlags)) != mixFlags)
    SDL_Log("Unable to initialize sound decoder: %s\n", Mix_GetError());

  /* Inicializando biblioteca de som */
  if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, MIX_DEFAULT_CHUNKSIZE))
  {
    SDL_Log("Unable to initialize audio: %s\n", Mix_GetError());
    exit(1);
  }
  /* Aloca canais de audio */
  Mix_AllocateChannels(32); /* Nao falha */

  /* Criando janela */
  this->window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
  if (this->window == nullptr)
  {
    SDL_Log("Unable to create window: %s\n", SDL_GetError());
    exit(1);
  }

  /* Criando renderer */
  this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
  if (this->renderer == nullptr)
  {
    SDL_Log("Unable to create renderer: %s\n", SDL_GetError());
    exit(1);
  }

  /* Inicializa State */
  this->state = new State();
}

/* Destrutor */
Game::~Game()
{
  /* Destruindo em ordem inversa a inicializacao */
  SDL_DestroyRenderer(this->renderer);
  SDL_DestroyWindow(this->window);
  Mix_CloseAudio();
  Mix_Quit();
  IMG_Quit();
  SDL_Quit();
}

/* State Getter */
State &Game::GetState()
{
  return *(this->state);
}

/* Renderer Getter */
SDL_Renderer *Game::GetRenderer()
{
  return this->renderer;
}

/* Runner */
void Game::Run()
{
  /* Verifica, controla e carrega as telas de jogo */
  /* Os dados de input sao recebidos e processados */
  /* Os objetos tem seus respectivos estados */
  /* Os objetos sao desenhados na tela */
  while (!this->state->QuitRequested())
  {
    InputManager::GetInstance().Update(); /* checa por inputs ante da atualizacao do estado */
    this->state->Update(0); /* parametro 0 e arbitrario e sera desconsiderado por enquanto */
    this->state->Render();
    /* Forca renderizacao */
    SDL_RenderPresent(this->renderer);
    /* Forca frame rate */
    SDL_Delay(33);
  }

  /* Libera recursos */
  Resources::ClearImages();
  Resources::ClearMusics();
  Resources::ClearSounds();
}