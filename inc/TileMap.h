#ifndef __TILE_MAP_H__
#define __TILE_MAP_H__

#include "Component.h"
#include "TileSet.h"

#include <vector>

class TileMap : public Component
{
  private:
    /* Atributos privados */
    std::vector<int> tileMatrix;
    TileSet* tileSet;

    int mapWidth;
    int mapHeight;
    int mapDepth;

  public:
    /* Metodos publicos */
    void Update(float dt);
    void Render();
    bool Is(std::string type);

    void Load(std::string file);
    void SetTileSet(TileSet* tileSet);
    int& At(int x, int y, int z = 0);
    void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);

    int GetWidth();
    int GetHeight();
    int GetDepth();

    /* Construtor */
    TileMap(GameObject& associated, std::string file, TileSet* tileSet);
    /* Destrutor */
    ~TileMap();
};

#endif