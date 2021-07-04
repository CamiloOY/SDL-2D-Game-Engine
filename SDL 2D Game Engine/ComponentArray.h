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
	void insertData(Entity entity, T component);
	void removeComponent(Entity entity);
	T& getComponent(Entity entity);
	void entityDestroyed(Entity entity);

private:
	llvm::DenseMap<Entity, T> component_array;
};