#include "../inc/InputManager.h"

#define INCLUDE_SDL
#include "../inc/SDL_include.h"

#include <iostream>

/* Construtor */
InputManager::InputManager() {
  /* inicializando arrays do mouse */
  for (int i=0; i<6; i++) {  
    this->mouseState[i] = false;
    this->mouseUpdate[i] = 0;
  }

  this->quitRequested = false;
  this->updateCounter = 0;
  this->mouseX = 0;
  this->mouseY = 0;
}

InputManager::~InputManager() {};

/* Retorna instancia do Singleton */
InputManager& InputManager::GetInstance() {
  static InputManager instance;
  return instance;
}

void InputManager::Update() {
  SDL_Event event;

  /* Obtem as coordenadas do mouse */
	SDL_GetMouseState(&this->mouseX, &this->mouseY);
  /* Reseta flag de quit */
  this->quitRequested = false;
  /* Incrementa contador */
  this->updateCounter++;

  /* Espera pelo acontecimento de eventos */
  while(SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        this->quitRequested = true;
      break;
      case SDL_MOUSEBUTTONDOWN:
        this->mouseState[event.button.button] = true;
        this->mouseUpdate[event.button.button] = this->updateCounter;
      break;
      case SDL_MOUSEBUTTONUP:
        this->mouseState[event.button.button] = false;
        this->mouseUpdate[event.button.button] = this->updateCounter;
      break;
      case SDL_KEYDOWN:
        if (!event.key.repeat) {
          this->keyState[event.key.keysym.sym] = true;
          this->keyUpdate[event.key.keysym.sym] = this->updateCounter;
        }
      break;
      case SDL_KEYUP:
        if (!event.key.repeat) {
          this->keyState[event.key.keysym.sym] = false;
          this->keyUpdate[event.key.keysym.sym] = this->updateCounter;
        }
      break;
    }
  }
}

bool InputManager::KeyPress(int key) {
  return (this->updateCounter == this->keyUpdate[key]) && this->keyState[key];
}

bool InputManager::KeyRelease(int key) {
  /* estado falso significa tecla nao pressionada */
  return (this->updateCounter == this->keyUpdate[key]) && !this->keyState[key];
}

bool InputManager::MousePress(int button) {
  return (this->updateCounter == this->mouseUpdate[button]) && this->mouseState[button];
}

bool InputManager::MouseRelease(int button) {
  return (this->updateCounter == this->mouseUpdate[button]) && !this->mouseState[button];
}

bool InputManager::isKeyDown(int key) {
  return this->keyState[key];
}

bool InputManager::isMouseDown(int button) {
  return this->mouseState[button];
}

int InputManager::GetMouseX() {
  return this->mouseX;
}

int InputManager::GetMouseY() {
  return this->mouseY;
}

bool InputManager::QuitRequested() {
  return this->quitRequested;
}