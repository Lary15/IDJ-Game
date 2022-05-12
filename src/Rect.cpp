#include "../inc/Rect.h"

/* Construtor sem parametros */
Rect::Rect()
{
  this->x = 0;
  this->y = 0;
  this->w = 0;
  this->h = 0;
}

/* Construtor com parametros */
Rect::Rect(float x, float y, float w, float h)
{
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
}

/* Implemta soma de Rect com Vec2*/
Rect Rect::operator+ (const Vec2& vec) {
  Rect tmp;

  tmp.x = this->x + vec.x;
  tmp.y = this->y + vec.y;

  return tmp;
}

/* Retorna coodernadas do centro de um retangulo */
Vec2 Rect::Center() {
  Vec2 center;

  center.x = this->w/2 + this->x;
  center.y = this->h/2 + this->y;

  return center;
}

/* Retorna distancia entre os centros de dois Rects */
double Rect::Distance(Rect& rec) {
  Vec2 center1, center2;

  center1 = this->Center();
  center2 = rec.Center();

  return center1.Distance(center2);
}

/* Verifica se ponto esta dentro do Rect */
bool Rect::Contains(const Vec2& point) {
  return (point.x >= this->x && point.x <= this->x+this->w) && (point.y >= this->y && point.y <= this->y+this->h);
}