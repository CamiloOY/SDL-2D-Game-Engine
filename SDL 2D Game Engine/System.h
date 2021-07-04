#pragma once

#include "Types.h"
#include <set>

class System {
public:
	std::set<Entity> entities; // Set of entities that match this system's signature
};