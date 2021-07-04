#include "EntityManager.h"
#include <assert.h>

EntityManager::EntityManager() {
	for(Entity e = 0; e < MAX_ENTITIES; e++) { // Initialise entity ID queue
		availableEntities.push_back(e);
	}
}

Entity EntityManager::createEntity() {
	assert(availableEntities.size() != 0); // Check that there are available IDs
	Entity id = availableEntities.front();
	availableEntities.pop_front();
	return id;
}

void EntityManager::destroyEntity(Entity entity) {
	// Make sure the entity can be destroyed
	assert(entity < MAX_ENTITIES);
	for(int i = 0; i < availableEntities.size(); i++) {
		assert(entity != availableEntities.at(i));
	}

	// Reset the entity's signature and make its ID available
	entitySignatures[entity].reset();
	availableEntities.push_back(entity);
}

Signature EntityManager::getSignature(Entity entity) {
	assert(entity < MAX_ENTITIES);
	return entitySignatures[entity];
}

void EntityManager::setSignature(Entity entity, Signature signature) {
	assert(entity < MAX_ENTITIES);
	entitySignatures[entity] = signature;
}
