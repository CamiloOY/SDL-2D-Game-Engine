#pragma once

#include "Types.h"
#include <llvm/ADT/DenseMap.h>
#include <memory>
#include "ComponentArray.h"

class ComponentManager {
public:
	
	template<typename T>
	void registerComponent() {
		const char* type_name = typeid(T).name();
		assert(component_types.find(type_name) == component_types.end()); // Ensure component hasn't already been registered
		assert(next_component_type != MAX_COMPONENTS); // Ensure we haven't reached maximum component count
		component_types.insert({type_name, next_component_type++}); // Assign a component type to the component then increment the counter
		component_arrays.insert({type_name, std::make_shared<ComponentArray<T>>()}); // Create a component array for the component
	}
	
	template<typename T>
	ComponentType getComponentType() {
		const char* type_name = typeid(T).name();
		assert(component_types.find(type_name) != component_types.end()); // Ensure component has been registered
		return component_types.lookup(type_name);
	}
	
	template<typename T>
	void addComponent(Entity entity, T component) {
		this->getComponentArray<T>()->insertData(entity, component);
	}
	
	template<typename T>
	void removeComponent(Entity entity) {
		this->getComponentArray<T>()->removeComponent(entity);
	}
	
	template<typename T>
	T& getComponent(Entity entity) {
		return this->getComponentArray<T>()->getComponent(entity);
	}

	void entityDestroyed(Entity entity);

private:
	llvm::DenseMap<const char*, ComponentType> component_types; // Map a component to its type (id)
	llvm::DenseMap<const char*, std::shared_ptr<IComponentArray>> component_arrays; // Map a component to its component array
	ComponentType next_component_type; // Tracks the next available component type
	
	template<typename T>
	std::shared_ptr<ComponentArray<T>> getComponentArray() {
		const char* type_name = typeid(T).name();
		assert(component_types.find(type_name) != component_types.end());
		return std::static_pointer_cast<ComponentArray<T>>(component_arrays.lookup(type_name));
	}
};