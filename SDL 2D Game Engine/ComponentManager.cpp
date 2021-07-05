#include "ComponentManager.h"

void ComponentManager::entityDestroyed(Entity entity) {
	for(auto pair : component_arrays) { // Remove all components from the entity
		pair.second.get()->entityDestroyed(entity);
	}
}