#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

class Component; /* evitar problemas com importacao circular */
#include "Component.h"
#include "Rect.h"

#include <vector>
#include <string>
#include <memory>

class GameObject
{
  private:
    /* Atributos privados */
    bool isDead;
    std::vector<std::unique_ptr<Component>> components;

  public:
    /* Atributos publicos */
    Rect box;

    /* Metodos publicos */
    void Update(float dt);
    void Render();
    bool IsDead();
    void RequestDelete();
    void AddComponent(Component* cpt);
    void RemoveComponent(Component* cpt);
    Component* GetComponent(std::string type);

    /* Contrutor e Destrutor */
    GameObject();
    ~GameObject();
};

#endif