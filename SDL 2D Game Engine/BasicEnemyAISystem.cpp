#include "BasicEnemyAISystem.h"
#include "Components.h"
#include <cmath>

void BasicEnemyAISystem::update() {
	for(Entity& entity : entities) {
		Transform& transform = manager.getComponent<Transform>(entity);
		BasicEnemyAI& ai = manager.getComponent<BasicEnemyAI>(entity);
		RectCollider& collider = manager.getComponent<RectCollider>(entity);

		// Check for collisions
		for(Entity collision : collider.collisions) {
			RectCollider& collided = manager.getComponent<RectCollider>(collision);
			if(collided.tag == "Player") { // If we've collided with a player, aggress on them
				ai.angered = true;
				ai.target = collision;
			}
		}
		if(ai.angered) {
			// Calculate the direction to the player
			Transform& target_transform = manager.getComponent<Transform>(ai.target);
			Vec2f direction_vector = target_transform.position - transform.position;
			direction_vector.normalise(); // Normalise the vector so that the AI doesn't instantly appear at the player's location
			transform.position.x += direction_vector.x; // Move towards the player
			transform.position.y += direction_vector.y;
		}
		else { // If the AI hasn't been angered then idle (move from left to right)
			transform.position.x += ai.speed * ai.direction;
			ai.travelled += ai.speed * ai.direction;
			if(abs(ai.travelled) >= abs(ai.distance)) {
				ai.direction *= -1;
			}
		}
	}
}