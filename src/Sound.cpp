#include "../inc/Sound.h"
#include "../inc/Resources.h"

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
  this->Stop();
}

void Sound::Play(int times) {
  this->channel = Mix_PlayChannel(DEFAULT_CHANNEL, this->chunk, times-1);

  if (this->channel == -1)
    SDL_Log("Unable to play sound: %s\n", Mix_GetError());
}

void Sound::Stop() {
  if (this->chunk != nullptr) {
    /* essa funcao sempre retorna 0, nao necessita de tratamento de erro */
    Mix_HaltChannel(this->channel);
  }
}

void Sound::Open(std::string file) {
  this->chunk = Resources::GetSound(file);
}

void Sound::Update(float dt) {

}

void Sound::Render() {

}

bool Sound::Is(std::string type) {
  return type == "Sound";
}
