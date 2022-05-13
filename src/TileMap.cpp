#include "../inc/TileMap.h"

#define INCLUDE_SDL
#include "../inc/SDL_include.h"

#include <fstream>
#include <sstream>

/* Construtor */
TileMap::TileMap(GameObject& associated, std::string file, TileSet* tileSet) : Component(associated) {
  this->tileSet = tileSet;
  this->Load(file);
}

/* Destrutor */
TileMap::~TileMap() {
  delete this->tileSet;
}

/* Le e salva valores de map file */
void TileMap::Load(std::string file) {
  std::fstream map;
  /* Abrindo arquivo map para leitura */
  map.open(file, std::ios::in);

  if (map) {
    std::string h, w, d, line, tile;
    /* Le valores iniciais de largura, altura e profundidade */
    std::getline(map, w, ',');
    std::getline(map, h, ',');
    std::getline(map, d, ',');

    this->mapWidth = std::stoi(w);
    this->mapHeight = std::stoi(h);
    this->mapDepth = std::stoi(d);

    /* Le valores da matriz de tiles */
    while (std::getline(map, line)) { /* captura uma linha e coloca em line*/
      std::istringstream lstream(line);
      /* captura cada tile conferindo valor separado por virgula */
      while(std::getline(lstream, tile, ',')) {
        /* Ignora linhas vazias do arquivo */
        if (tile == "\r") break;
        /* adiciona valor lido decrementado em 1 para que tiles 0 se tornem -1 */
        this->tileMatrix.push_back(std::stoi(tile)-1);
      }
    }

    map.close();
  }
  else {
    SDL_Log("Unable to open map file: %s\n", file.c_str());
  }
}

void TileMap::SetTileSet(TileSet* tileSet) {
  this->tileSet = tileSet;
}

int& TileMap::At(int x, int y, int z) {
  /* transformando coord 3D em index 1D */
  int index = x + this->mapWidth*y + this->mapWidth*this->mapHeight*z;

  return this->tileMatrix[index];
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY) {
  for (int x=0; x<this->mapWidth; x++) {
    for (int y=0; y<this->mapHeight; y++) {
      this->tileSet->RenderTile(this->At(x, y, layer), x*this->tileSet->GetTileWidth(), y*this->tileSet->GetTileHeight());
    }
  }
}

void TileMap::Update(float dt) {

}

void TileMap::Render() {
  for (int i=0; i<this->mapDepth; i++) {
    this->RenderLayer(i, this->associated.box.x, this->associated.box.y);
  }
}

bool TileMap::Is(std::string type) {
  return type == "TileMap";
}


int TileMap::GetWidth() {
  return this->mapWidth;
}

int TileMap::GetHeight() {
  return this->mapHeight;
}

int TileMap::GetDepth() {
  return this->mapDepth;
}