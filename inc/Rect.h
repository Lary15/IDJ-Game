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
    Vec2 Center();
    double Distance(Rect& rec);
    bool Contains(const Vec2& point);

    /* Construtores */
    Rect();
    Rect(float x, float y, float w, float h);

    /* Operadores */
    Rect operator+ (const Vec2& vec);
};

#endif