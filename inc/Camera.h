#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "GameObject.h"
#include "Vec2.h"

class Camera
{
  private:
    /* Atributos privados */
    static GameObject* focus;
  public:
    /* Atributos publicos */
    static Vec2 pos;
    static Vec2 speed;

    /* Metodos Publicos */
    static void Follow(GameObject* newFocus);
    static void Unfollow();
    static void Update(float dt);
};

#endif