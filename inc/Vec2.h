#ifndef __VEC2_H__
#define __VEC2_H__

class Vec2
{
  private:
  public:
  /* Atributos publicos */
  float x, y;

  /* Metodos publicos */
  double magnitude();
  Vec2 normal_vector();
  double distance(Vec2& vec);

  /* Construtores */
  Vec2();
  Vec2(float x, float y);

  /* Operadores */
  Vec2 operator+ (const Vec2& vec);
  Vec2 operator- (const Vec2& vec);
  Vec2 operator* (const double& scalar);
  Vec2 operator* (const int& scalar);
};

#endif