#include "../inc/Face.h"
#include "../inc/Sound.h"

#include <chrono>
#include <thread>

#define DEFAULT_HITPOINTS 30;

Face::Face(GameObject& associated) : Component(associated)
{
  this->hitpoints = DEFAULT_HITPOINTS;
}

void Face::Damage(int damage) {
  this->hitpoints -= damage;

  if (this->hitpoints <= 0) {
    associated.RequestDelete();
    Component* sound = associated.GetComponent("Sound");

    /* caso nao seja nulo */
    if (sound) {
      ((Sound*) sound)->Play();
      /* Espera play do som */
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  }
}

void Face::Update(float dt) {

}

void Face::Render() {
  
}

bool Face::Is(std::string type) {
  return type == "Face";
}