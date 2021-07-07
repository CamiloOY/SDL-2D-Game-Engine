#include "MovementSystem.h"
#include "Types.h"
#include "Components.h"

void MovementSystem::update() {
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
	this->move(direction);
}

void MovementSystem::move(Vec2 direction) {
	for(Entity& entity : entities) {
		Transform& transform = manager.getComponent<Transform>(entity);
		Movement& movement = manager.getComponent<Movement>(entity);
		transform.position.x += movement.speed * direction.x;
		transform.position.y += movement.speed * direction.y;
	}
}
