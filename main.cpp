#include "inc/Game.h"
#include <iostream>

int main(int argc, char** argv) {
  /* Cria um game */
  Game game = Game::GetInstance();
  /* Game loop */
  game.Run();

  return 0;
}