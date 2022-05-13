#include "../inc/Face.h"
#include "../inc/Sound.h"
#include "../inc/InputManager.h"

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
  InputManager& input = InputManager::GetInstance();
  /* Confere pressionamento de qualquer botao de mouse */
  for (int i=0; i<6; i++) {
    if (input.MousePress(i) && this->associated.box.Contains({ (float) input.GetMouseX(), (float) input.GetMouseY()})) {
      this->Damage(std::rand() % 10 + 10);
      // Sai do loop (só queremos acertar um)
      break;
    }
  }
}

void Face::Render() {
  
}

bool Face::Is(std::string type) {
  return type == "Face";
}