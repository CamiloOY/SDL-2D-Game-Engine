#pragma once

#include "System.h"
#include "Manager.h"
#include "InputManager.h"
#include "CollisionSystem.h"
#include <memory>

extern Manager manager;
extern InputManager inputManager;
extern std::shared_ptr<CollisionSystem> collisionSystem;

class MovementSystem : public System {
public:
	void update();

private:
	void move(Vec2 direction); // Moves entities in the provided direction
};