#ifndef __CAMERA_FOLLOWER_H__
#define __CAMERA_FOLLOWER_H__

#include "Component.h"

class CameraFollower : public Component
{
  private:
  public:
    /* Metodos publicos */
    void Update(float dt);
    void Render();
    bool Is(std::string type);
    /* Construtor */  
    CameraFollower(GameObject& go);
};


#endif
