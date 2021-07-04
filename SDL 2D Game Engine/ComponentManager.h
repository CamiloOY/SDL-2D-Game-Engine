#pragma once

#include "Types.h"
#include <llvm/ADT/DenseMap.h>
#include <memory>
#include "ComponentArray.h"

class ComponentManager {
public:
	template<typename T> void registerComponent();
	template<typename T> ComponentType getComponentType();
	template<typename T> void addComponent(Entity entity, T component);
	template<typename T> void removeComponent(Entity entity);
	template<typename T> T& getComponent(Entity entity);
	void entityDestroyed(Entity entity);

private:
	llvm::DenseMap<const char*, ComponentType> component_types; // Map a component to its type (id)
	llvm::DenseMap<const char*, std::shared_ptr<IComponentArray>> component_arrays; // Map a component to its component array
	ComponentType next_component_type; // Tracks the next available component type
	template<typename T> std::shared_ptr<ComponentArray<T>> getComponentArray();
};