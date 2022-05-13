#ifndef __STATE_H__
#define __STATE_H__

#include "Sprite.h"
#include "Music.h"
#include "GameObject.h"

#include <vector>
#include <memory>

class State {
  private:
    /* Atributos privados */
    Sprite bg;
    Music music;
    bool quitRequested;
    std::vector<std::unique_ptr<GameObject>> objectArray;

    /* Metodos privados */
    void AddObject(int mouseX, int mouseY);

  public:
    /* Metodos publicos */
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();

    /* Construtor */
    State();
    /* Destrutor */
    ~State();
};

#endif