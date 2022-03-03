#define INCLUDE_SDL_IMAGE

#include "../inc/SDL_include.h"
#include "../inc/Sprite.h"
#include "../inc/Game.h"

/* Construtor sem parametro */
Sprite::Sprite()
{
  this->texture = nullptr;
}

/* Construtor com parametro file */
Sprite::Sprite(std::string file)
{
  this->texture = nullptr;
  this->Open(file);
}

/* Destrutor */
Sprite::~Sprite()
{
  if (this->texture != nullptr)
    SDL_DestroyTexture(this->texture);
}

void Sprite::Open(std::string file)
{
  /* Desaloca imagem caso exista */
  if (this->texture != nullptr)
    SDL_DestroyTexture(this->texture);

  /* Carrega nova imagem */
  this->texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());

  /* Trata possivel erro de carregamento */
  if (this->texture == nullptr)
    SDL_Log("Unable to load texture: %s\n", IMG_GetError());

  /* Descobrindo dimensoes da imagem */
  if (SDL_QueryTexture(this->texture, nullptr, nullptr, &(this->width), &(this->height)))
    SDL_Log("Unable to query texture: %s\n", SDL_GetError());

  /* Seta clip da imagem */
  this->SetClip(0, 0, this->width, this->height);
}

void Sprite::SetClip(int x, int y, int w, int h)
{
  this->clipRect.x = x;
  this->clipRect.y = y;
  this->clipRect.w = w;
  this->clipRect.h = h;
}

void Sprite::Render(int x, int y)
{
  SDL_Rect dstRect = {x, y, this->clipRect.w, this->clipRect.h};

  if(SDL_RenderCopy(Game::GetInstance().GetRenderer(), this->texture, &(this->clipRect), &dstRect))
    SDL_Log("Unable to render copy: %s\n", SDL_GetError());
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