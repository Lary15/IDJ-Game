#ifndef __RECT_H__
#define __RECT_H__

#include "Vec2.h"

class Rect
{
  private:

  public:
    /* Atributos publicos*/
    float x, y, w, h;

    /* Metodos publicos */
    Vec2 center();
    double distance(Rect& rec);
    bool inside(Vec2& point);

    /* Construtores */
    Rect();
    Rect(float x, float y, float w, float h);

    /* Operadores */
    Rect operator+ (const Vec2& vec);
};

#endif