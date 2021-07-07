#pragma once

#include "System.h"
#include "Manager.h"

extern Manager manager;

class BasicEnemyAISystem : public System {
public:
	void update();
};