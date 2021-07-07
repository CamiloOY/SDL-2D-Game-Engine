#pragma once

#include "System.h"
#include "Manager.h"
#include "InputManager.h"

extern Manager manager;
extern InputManager inputManager;

class MovementSystem : public System {
public:
	void update();

private:
	void move(Vec2 direction); // Moves entities in the provided direction
};