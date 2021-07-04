#pragma once

#include "Types.h"
#include <deque>
#include <array>

class EntityManager {
public:
	EntityManager();
	Entity createEntity();
	void destroyEntity(Entity entity);
	Signature getSignature(Entity entity);
	void setSignature(Entity entity, Signature signature);

private:
	std::deque<Entity> availableEntities;
	std::array<Signature, MAX_ENTITIES> entitySignatures;
};

