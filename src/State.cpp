#define INCLUDE_SDL

#include "../inc/SDL_include.h"
#include "../inc/State.h"

/* Construtor */
State::State()
{
  this->quitRequested = false;

  /* Instanciar Sprite e Music */
  this->LoadAssets();
  this->music.Play(); /* Temporario - apenas para testar musica */
}

void State::LoadAssets()
{
  /* Pre-carrega os assets */
  this->bg.Open("assets/img/ocean.jpg");
  this->music.Open("assets/audio/stageState.ogg");
}

void State::Update(float dt)
{
  if(SDL_QuitRequested())
    this->quitRequested = true;
}

void State::Render() {
  /* Render do bg */
  this->bg.Render(0,0);
}

bool State::QuitRequested() {
  return this->quitRequested;
}