#include "ComponentManager.h"

template<typename T>
void ComponentManager::registerComponent() {
	const char* type_name = typeid(T).name();
	assert(component_types.find(type_name) == component_types.end()); // Ensure component hasn't already been registered
	assert(next_component_type != MAX_COMPONENTS); // Ensure we haven't reached maximum component count
	component_types.insert({type_name, next_component_type++}); // Assign a component type to the component then increment the counter
	component_arrays.insert({type_name, std::make_shared<ComponentArray<T>>()}); // Create a component array for the component
}

template<typename T>
ComponentType ComponentManager::getComponentType() {
	const char* type_name = typeid(T).name();
	assert(component_types.find(type_name) != component_types.end()); // Ensure component has been registered
	return component_types.lookup(type_name);
}

template<typename T>
void ComponentManager::addComponent(Entity entity, T component) {
	this->getComponentArray<T>()->insertData(entity, component);
}

template<typename T>
void ComponentManager::removeComponent(Entity entity) {
	this->getComponentArray<T>()->removeComponent(entity);
}

template<typename T>
T& ComponentManager::getComponent(Entity entity) {
	return this->getComponentArray<T>()->getComponent(entity);
}

void ComponentManager::entityDestroyed(Entity entity) {
	for(auto pair : component_arrays) { // Remove all components from the entity
		pair.second.get()->entityDestroyed(entity);
	}
}

template<typename T>
std::shared_ptr<ComponentArray<T>> ComponentManager::getComponentArray() {
	const char* type_name = typeid(T).name();
	assert(component_types.find(type_name) != component_types.end());
	return std::static_pointer_cast<ComponentArray<T>>(component_arrays.lookup(type_name));
}