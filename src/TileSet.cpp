#include "../inc/TileSet.h"

TileSet::TileSet(int tileWidth, int tileHeight, std::string file) : tileSet(*new GameObject, file) {
  if (this->tileSet.IsOpen()) {
    /* Calcula quantidade de linhas e colunas no tileSet */
    this->rows = this->tileSet.GetHeight() / tileHeight;
    this->columns = this->tileSet.GetWidth() / tileWidth;
  }
}

void TileSet::RenderTile(unsigned index, float x, float y) {
  /* Verifica se index esta em um range valido */
  if (index <= unsigned (this->rows*this->columns-1)) {
    /* calcula linha e coluna referente a index */
    int row = index/this->columns, column = index%this->columns;
    /* especifica clip a ser usado como tile escolhido */
    this->tileSet.SetClip(this->tileWidth*column, this->tileHeight*row, this->tileWidth, tileHeight);
    /* renderiza tile na tela */
    this->tileSet.Render(x, y);
  }
}

int TileSet::GetTileWidth() {
  return this->tileWidth;
}

int TileSet::GetTileHeight() {
  return this->tileHeight;
}