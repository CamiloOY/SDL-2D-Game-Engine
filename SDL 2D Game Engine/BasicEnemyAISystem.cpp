#include "BasicEnemyAISystem.h"
#include "Components.h"
#include <cmath>

void BasicEnemyAISystem::update() {
	for(Entity& entity : entities) {
		Transform& transform = manager.getComponent<Transform>(entity);
		BasicEnemyAI& ai = manager.getComponent<BasicEnemyAI>(entity);
		RectCollider& collider = manager.getComponent<RectCollider>(entity);
		for(Entity collision : collider.collisions) {
			RectCollider& collided = manager.getComponent<RectCollider>(collision);
			if(collided.tag == "Player") {
				ai.angered = true;
				ai.target = collision;
			}
		}
		if(ai.angered) {
			Transform& target_transform = manager.getComponent<Transform>(ai.target);
			Vec2f direction_vector = target_transform.position - transform.position;
			direction_vector.normalise();
			transform.position.x += direction_vector.x;
			transform.position.y += direction_vector.y;
		}
		else {
			transform.position.x += ai.speed * ai.direction;
			ai.travelled += ai.speed * ai.direction;
			if(abs(ai.travelled) >= abs(ai.distance)) {
				ai.direction *= -1;
			}
		}
	}
}