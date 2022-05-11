#include "../inc/Vec2.h"

#include <cmath>

/* Construtor sem parametros */
Vec2::Vec2()
{
  this->x = 0;
  this->y = 0;
} 

/* Construtor com parametros */
Vec2::Vec2(float x, float y)
{
  this->x = x;
  this->y = y;
}

/* Implementa soma entre dois vetores R2 */
Vec2 Vec2::operator+(const Vec2& vec) {
  Vec2 tmp;

  tmp.x = this->x + vec.x;
  tmp.y = this->y + vec.y;

  return tmp;
}

/* Implementa subtracao entre dois vetores R2 */
Vec2 Vec2::operator-(const Vec2& vec) {
  Vec2 tmp;

  tmp.x = this->x - vec.x;
  tmp.y = this->y - vec.y;

  return tmp;
}

/* Implementa multiplicacao por escalar de ponto flutuante */
Vec2 Vec2::operator*(const double& scalar) {
  Vec2 tmp;

  tmp.x = this->x * scalar;
  tmp.y = this->y * scalar;

  return tmp;
}

/* Implementa multiplicacao por escalar de ponto fixo */
Vec2 Vec2::operator*(const int& scalar) {
  Vec2 tmp;

  tmp.x = this->x * scalar;
  tmp.y = this->y * scalar;

  return tmp;
}

/* Calcula magnitude do vetor */
double Vec2::magnitude() {
  return sqrt(this->x*this->x + this->y*this->y);
}

/* Retorna um vetor normalizado */
Vec2 Vec2::normal_vector() {
  Vec2 tmp;
  double mag = this->magnitude();

  tmp.x = this->x/mag;
  tmp.y = this->y/mag;

  return tmp;
}

/* Calcula distancia entre ponto A e B, sendo argumento vec o ponto B */
double Vec2::distance(Vec2& vec) {
  Vec2 tmp;
  tmp = *this - vec;
  return tmp.magnitude();
}