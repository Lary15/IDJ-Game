#ifndef __STATE_H__
#define __STATE_H__

#include "Sprite.h"
#include "Music.h"

class State {
  private:
    /* Atributos privados */
    Sprite bg;
    Music music;
    bool quitRequested;

  public:
    /* Metodos publicos */
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();

    /* Construtor */
    State();
};

#endif