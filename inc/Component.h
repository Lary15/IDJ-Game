#ifndef __COMPONENT_H__
#define __COMPONENT_H__

class GameObject; /* evitar problemas com importacao circular */
#include "GameObject.h"

#include <string>

/* Interface */
class Component
{
  private:
  protected:
    GameObject& associated;

  public:
    /* Metodos publicos */
    virtual void Update(float dt) = 0;
    virtual void Render() = 0;
    virtual bool Is(std::string type) = 0;

    /* Construtor e Destrutor */
    Component(GameObject& associated);
    virtual ~Component();
};

#endif