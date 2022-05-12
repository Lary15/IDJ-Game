#include "../inc/GameObject.h"


/* Construtor */
GameObject::GameObject()
{
  this->isDead = false;
}

/* Destrutor */
GameObject::~GameObject()
{
  this->components.clear();
}

void GameObject::Update(float dt) {
  for (unsigned int i = 0; i < this->components.size() ; i++)
  {
    this->components[i]->Update(dt);
  }
}

void GameObject::Render() {
  for (unsigned int i = 0; i < this->components.size() ; i++)
  {
    this->components[i]->Render();
  }
}

bool GameObject::IsDead() {
  return this->isDead;
}

void GameObject::RequestDelete() {
  this->isDead = true;
}

void GameObject::AddComponent(Component* cpt) {
  this->components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt) {
  for (unsigned int i = 0; i < this->components.size() ; i++)
  {
    if (cpt == this->components[i].get()) {
      /* remove elemento do vector */
      this->components.erase(this->components.begin()+i);
      return;
    }
  }
}

Component* GameObject::GetComponent(std::string type) {
  for (unsigned int i = 0; i < this->components.size() ; i++)
  {
    if (this->components[i]->Is(type)) {
      return this->components[i].get();
    }
  }

  return nullptr;
}