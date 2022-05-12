#include "../inc/Component.h"

Component::Component(GameObject& associated) : associated(associated) {};

Component::~Component() {}