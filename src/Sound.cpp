#include "../inc/Sound.h"

#define DEFAULT_CHANNEL -1

/* Construtor sem file */
Sound::Sound(GameObject& associated) : Component(associated)
{
  this->chunk = nullptr;
}

/* Construtor com file */
Sound::Sound(GameObject& associated, std::string file) : Sound(associated)
{
  this->Open(file);
}

/* Destrutor */
Sound::~Sound()
{
  if (this->chunk) {
    this->Stop();
    Mix_FreeChunk(this->chunk);
  }
}

void Sound::Play(int times) {
  this->channel = Mix_PlayChannel(DEFAULT_CHANNEL, this->chunk, times-1);

  if (this->channel == -1)
    SDL_Log("Unable to play music: %s\n", Mix_GetError());
}

void Sound::Stop() {
  if (this->chunk != nullptr) {
    /* essa funcao sempre retorna 0, nao necessita de tratamento de erro */
    Mix_HaltChannel(this->channel);
  }
}

void Sound::Open(std::string file) {
  this->chunk = Mix_LoadWAV(file.c_str());

  if (!this->chunk)
    SDL_Log("Unable to play music: %s\n", Mix_GetError());
}

void Sound::Update(float dt) {

}

void Sound::Render() {

}

bool Sound::Is(std::string type) {
  return type == "Sound";
}
