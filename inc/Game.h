#ifndef __GAME_H__
#define __GAME_H__

#define INCLUDE_SDL

#include "SDL_include.h"
#include "State.h"

#include <string>

#define SCREEN_WIDTH  1024
#define SCREEN_HEIGHT 600

class Game {
  private:
    /* Atributos privados */
    static Game* instance;
    State* state;
    SDL_Window* window;
    SDL_Renderer* renderer;

    int frameStart;
    float dt;

    /* Metodos Privados */
    void CalculateDeltaTime();

    /* Construtor */
    Game(std::string title, int width, int height);

  public:
    /* Destrutor */
    ~Game();
    
    /* Metodos publicos */
    void Run();
    static Game& GetInstance();
    SDL_Renderer* GetRenderer();
    State& GetState();

    float GetDeltaTime();
};

#endif