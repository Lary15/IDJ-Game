#include "../inc/CameraFollower.h"
#include "../inc/Camera.h"

CameraFollower::CameraFollower(GameObject& go) : Component(go) {}

void CameraFollower::Update(float dt) {
  this->associated.box.x = Camera::pos.x;
  this->associated.box.y = Camera::pos.y;
}

void CameraFollower::Render() {}

bool CameraFollower::Is(std::string type) {
  return type == "CameraFollower";
}