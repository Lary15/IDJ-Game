#define INCLUDE_SDL_IMAGE

#include "../inc/SDL_include.h"
#include "../inc/Sprite.h"
#include "../inc/Game.h"
#include "../inc/Resources.h"

/* Construtor sem parametro */
Sprite::Sprite(GameObject& associated) : Component(associated)
{
  this->texture = nullptr;
}

/* Construtor com parametro file */
Sprite::Sprite(GameObject& associated, std::string file) : Sprite(associated)
{
  this->Open(file);
}

/* Destrutor */
Sprite::~Sprite()
{
}

void Sprite::Open(std::string file)
{
  /* Carrega nova imagem */
  this->texture = Resources::GetImage(file);

  /* Descobrindo dimensoes da imagem */
  if (SDL_QueryTexture(this->texture, nullptr, nullptr, &(this->width), &(this->height)))
    SDL_Log("Unable to query texture: %s\n", SDL_GetError());

  /* Seta clip da imagem */
  this->SetClip(0, 0, this->width, this->height);

  /* Guarda valores de altura e largura na box do GameObject */
  this->associated.box.w = this->width;
  this->associated.box.h = this->height;
}

void Sprite::SetClip(int x, int y, int w, int h)
{
  this->clipRect.x = x;
  this->clipRect.y = y;
  this->clipRect.w = w;
  this->clipRect.h = h;
}

void Sprite::Update(float dt)
{
}

/* Render com argumento de coordenadas x e y */
void Sprite::Render(int x, int y)
{
  SDL_Rect dstRect = {x, y, this->clipRect.w, this->clipRect.h};

  if(SDL_RenderCopy(Game::GetInstance().GetRenderer(), this->texture, &(this->clipRect), &dstRect))
    SDL_Log("Unable to render copy: %s\n", SDL_GetError());
}

void Sprite::Render() {
  this->Render((int) this->associated.box.x, (int) this->associated.box.y);
}

bool Sprite::Is(std::string type) {
  return type == "Sprite";
}

/* Width Getter */
int Sprite::GetWidth() {
  return this->width;
}

/* Height Getter */
int Sprite::GetHeight() {
  return this->height;
}

bool Sprite::IsOpen() {
  return this->texture != nullptr;
}