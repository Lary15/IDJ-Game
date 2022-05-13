#include "../inc/Camera.h"
#include "../inc/InputManager.h"
#include "../inc/Game.h"

/* Declara variaveis estaticas */
GameObject* Camera::focus;
Vec2 Camera::pos(0,0);
Vec2 Camera::speed(100,100);

void Camera::Follow(GameObject* newFocus) {
  focus = newFocus;
}

void Camera::Unfollow() {
  focus = nullptr;
}

void Camera::Update(float dt) {
  if (focus) {
    /* Centraliza na tela*/
    pos.x = SCREEN_WIDTH/2;
    pos.y = SCREEN_HEIGHT/2;
  }
  else {
    InputManager& input = InputManager::GetInstance();

    if (input.isKeyDown(UP_ARROW_KEY))
      pos.y += speed.y*-1*dt; /* levando em consideracao que o eixo y esta para baixo */
    if (input.isKeyDown(RIGHT_ARROW_KEY))
      pos.x += speed.x*dt;
    if (input.isKeyDown(DOWN_ARROW_KEY))
      pos.y += speed.y*dt;
    if (input.isKeyDown(LEFT_ARROW_KEY))
      pos.x += speed.x*-1*dt;
  }
}