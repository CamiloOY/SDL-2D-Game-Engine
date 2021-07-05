#pragma once

#include "Types.h"
#include <set>
#include <llvm/ADT/DenseSet.h>

class System {
public:
	virtual void update(){};
	virtual void render(){};
	llvm::DenseSet<Entity> entities; // Set of entities that match this system's signature
};