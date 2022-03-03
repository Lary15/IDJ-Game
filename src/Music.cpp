#define INCLUDE_SDL

#include "../inc/SDL_include.h"
#include "../inc/Music.h"

/* Construtor sem parametro */
Music::Music()
{
  this->music = nullptr;
}

/* Construtor com parametro file */
Music::Music(std::string file)
{
  this->music = nullptr;
  this->Open(file);
}

/*Destrutor*/
Music::~Music()
{
  /* Chama stop */
  this->Stop();
  /* Libera musica da memoria */
  Mix_FreeMusic(this->music);
}

void Music::Play(int times)
{
  if (Mix_PlayMusic(this->music, times))
    SDL_Log("Unable to play music: %s\n", Mix_GetError());
}

void Music::Stop(int msToStop)
{
  if (Mix_FadeOutMusic(msToStop))
    SDL_Log("Unable to stop music: %s\n", Mix_GetError());
}

void Music::Open(std::string file)
{
  this->music = Mix_LoadMUS(file.c_str());

  if (this->music == nullptr)
    SDL_Log("Unable to load music: %s\n", Mix_GetError());
}

bool Music::IsOpen()
{
  return this->music != nullptr;
}
