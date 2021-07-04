#include "ComponentArray.h"

template<typename T>
void ComponentArray<T>::insertData(Entity entity, T component) {
	assert(component_array.find(entity) == component_array.end()); // Check the entity isn't already in the array
	component_array.insert({entity, component});
}

template<typename T>
void ComponentArray<T>::removeComponent(Entity entity) {
	assert(component_array.find(entity) != component_array.end()); // Check the entity is in the array
	component_array.erase(Entity);
}

template<typename T>
T& ComponentArray<T>::getComponent(Entity entity) {
	assert(component_array.find(entity) != component_array.end()); // Check the entity is in the array
	return component_array.lookup(entity);
}

template<typename T>
void ComponentArray<T>::entityDestroyed(Entity entity) { // Remove the component if possible
	if(component_array.find(entity) != component_array.end()) {
		this->removeComponent(entity);
	}
}
