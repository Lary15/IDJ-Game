#ifndef __SPRITE_H__
#define __SPRITE_H__

#define INCLUDE_SDL

#include "SDL_include.h"
#include "Component.h"

#include <string>

class Sprite : public Component {
  private:
    /* Atributos privados */
    SDL_Texture* texture;
    int width;
    int height;
    SDL_Rect clipRect;

  public:
    /* Metodos publicos */
    void Render();
    void Render(int x, int y);
    void Update(float dt);
    bool Is(std::string type);

    void Open(std::string file);
    void SetClip(int x, int y, int w, int h);
    int GetWidth();
    int GetHeight();
    bool IsOpen();

    /* Construtores */
    Sprite(GameObject& associated);
    Sprite(GameObject& associated, std::string file);

    /* Destrutor */
    ~Sprite();
};

#endif