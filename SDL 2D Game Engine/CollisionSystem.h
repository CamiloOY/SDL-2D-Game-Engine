#pragma once

#include "System.h"
#include "llvm/ADT/SmallSet.h"
#include "Manager.h"

extern Manager manager;

class CollisionSystem : public System {
public:
	void update();
	void render();
};