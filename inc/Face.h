#ifndef __FACE_H__
#define __FACE_H__

#include "GameObject.h"

class Face : public Component
{
  private:
    /* Atributos privados */
    int hitpoints;

  public:
    /* Metodos publicos */
    void Update(float dt);
    void Render();
    bool Is(std::string type);

    void Damage(int damage);

    /* Construtor */
    Face(GameObject& associated);
};

#endif