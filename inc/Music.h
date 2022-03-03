#ifndef __MUSIC_H__
#define __MUSIC_H__

#define INCLUDE_SDL_MIXER

#include "SDL_include.h"

#include <string>

class Music {
  private:
    /* Atributos privados */
    Mix_Music* music;

  public:
    /* Metodos publicos */
    void Play(int times = -1);
    void Stop(int msToStop = 1500);
    void Open(std::string file);
    bool IsOpen();

    /* Construtores */
    Music();
    Music(std::string file);

    /* Destrutor */
    ~Music();
};

#endif