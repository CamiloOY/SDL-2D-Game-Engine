#include "SystemManager.h"

void SystemManager::entityDestroyed(Entity entity) {
	for(auto system : systems) {
		system.second->entities.erase(entity);
	}
}

void SystemManager::entitySignatureChanged(Entity entity, Signature signature) {
	for(auto system : systems) { // For each system
		Signature system_signature = signatures.lookup(system.first);
		if((signature & system_signature) == system_signature) { // If the system signature and entity signature match
			system.second->entities.insert(entity); // Add the entity to the system
		}
		else {
			system.second->entities.erase(entity); // Otherwise remove the entity from the system
		}
	}
}

void SystemManager::update() {
	for(auto system : systems) {
		system.second->update();
	}
}

void SystemManager::render() {
	for(auto system : systems) {
		system.second->render();
	}
}
