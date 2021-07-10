#include "MovementSystem.h"
#include "Types.h"
#include "Components.h"
#include <iostream>

void MovementSystem::update() {
	// Build direction vector
	Vec2 direction = {0, 0};
	if(inputManager.getCommand(Command::MOVE_LEFT)) {
		direction.x -= 1;
	}
	if(inputManager.getCommand(Command::MOVE_RIGHT)) {
		direction.x += 1;
	}
	if(inputManager.getCommand(Command::MOVE_UP)) {
		direction.y -= 1;
	}
	if(inputManager.getCommand(Command::MOVE_DOWN)) {
		direction.y += 1;
	}

	this->move(direction); // Move
}

void MovementSystem::move(Vec2 direction) {
	for(Entity& entity : entities) {
		Transform& transform = manager.getComponent<Transform>(entity);
		Movement& movement = manager.getComponent<Movement>(entity);
		for(std::pair<Entity, Entity> collision : collisionSystem->collisions) {
			RectCollider& collider_1 = manager.getComponent<RectCollider>(collision.first);
			RectCollider& collider_2 = manager.getComponent<RectCollider>(collision.second);
			std::cout << collider_1.tag << " collided with " << collider_2.tag << std::endl;
		}
		transform.position.x += movement.speed * direction.x;
		transform.position.y += movement.speed * direction.y;
	}
}
