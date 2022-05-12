#ifndef __TILE_SET_H__
#define __TILE_SET_H__

#include "Sprite.h"

#include <string>

class TileSet
{
  private:
    /* Atributos privados */
    Sprite tileSet;
    int rows, columns;
    int tileWidth, tileHeight;

  public:
    /* Metodos publicos */
    void RenderTile(unsigned index, float x, float y);
    int GetTileWidth();
    int GetTileHeight();

    /* Construtor */
    TileSet(int tileWidth, int tileHeight, std::string file);
};

#endif