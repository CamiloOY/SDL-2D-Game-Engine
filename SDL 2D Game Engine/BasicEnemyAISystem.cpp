#include "BasicEnemyAISystem.h"
#include "Components.h"
#include <cmath>

void BasicEnemyAISystem::update() {
	for(Entity& entity : entities) {
		Transform& transform = manager.getComponent<Transform>(entity);
		BasicEnemyAI& ai = manager.getComponent<BasicEnemyAI>(entity);
		transform.position.x += ai.speed * ai.direction;
		ai.travelled += ai.speed * ai.direction;
		if(abs(ai.travelled) >= abs(ai.distance)) {
			ai.direction *= -1;
		}
	}
}