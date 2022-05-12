#ifndef __SOUND_H__
#define __SOUND_H__

#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include "Component.h"

class Sound : public Component
{
  private:
    /* Atributos privados */
    Mix_Chunk* chunk;
    int channel;

  public:
    /* Metodos Publicos */
    void Update(float dt);
    void Render();
    bool Is(std::string type);

    void Play(int times = 1);
    void Stop();
    void Open(std::string file);
    bool IsOpen();

    /* Construtores*/
    Sound(GameObject& associated);
    Sound(GameObject& associated, std::string file);
    /* Destrutor */
    ~Sound();
};

#endif
