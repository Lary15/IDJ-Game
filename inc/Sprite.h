#ifndef __SPRITE_H__
#define __SPRITE_H__

#define INCLUDE_SDL

#include "SDL_include.h"

#include <string>

class Sprite {
  private:
    /* Atributos privados */
    SDL_Texture* texture;
    int width;
    int height;
    SDL_Rect clipRect;

  public:
    /* Metodos publicos */
    void Open(std::string file);
    void SetClip(int x, int y, int w, int h);
    void Render(int x, int y);
    int GetWidth();
    int GetHeight();
    bool IsOpen();

    /* Construtores */
    Sprite();
    Sprite(std::string file);

    /* Destrutor */
    ~Sprite();
};

#endif