#pragma once

#include "Types.h"
#include <llvm/ADT/DenseMap.h>

class IComponentArray {
public:
	virtual ~IComponentArray() = default;
	virtual void entityDestroyed(Entity entity) = 0;
};

template<typename T>
class ComponentArray: public IComponentArray {
public:
	void insertData(Entity entity, T component) {
		assert(component_array.find(entity) == component_array.end()); // Check the entity isn't already in the array
		component_array.insert({entity, component});
	}

	void removeComponent(Entity entity) {
		assert(component_array.find(entity) != component_array.end()); // Check the entity is in the array
		component_array.erase(entity);
	}

	T& getComponent(Entity entity) {
		assert(component_array.find(entity) != component_array.end()); // Check the entity is in the array
		return component_array[entity];
	}

	void entityDestroyed(Entity entity) {
		if(component_array.find(entity) != component_array.end()) {
			this->removeComponent(entity);
		}
	}

private:
	llvm::DenseMap<Entity, T> component_array;
};