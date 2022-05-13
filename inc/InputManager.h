#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

#include <unordered_map>

/* Macros */
#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define SPACE_KEY SDLK_SPACE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT

class InputManager
{
  private:
    /* Atributos privados */
    bool mouseState[6];
    int mouseUpdate[6];

    std::unordered_map<int, bool> keyState;
    std::unordered_map<int, int> keyUpdate;    

    bool quitRequested;
    int updateCounter;
    int mouseX, mouseY;

    /* Construtor e Destrutor privados */
    InputManager();
    ~InputManager();

  public:
    /* Metodos publicos */
    void Update();

    bool KeyPress(int key);
    bool KeyRelease(int key);
    bool isKeyDown(int key);

    bool MousePress(int button);
    bool MouseRelease(int button);
    bool isMouseDown(int button);

    int GetMouseX();
    int GetMouseY();

    bool QuitRequested();

    static InputManager& GetInstance();
};

#endif