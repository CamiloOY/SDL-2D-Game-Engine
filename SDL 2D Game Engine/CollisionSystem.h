#pragma once

#include "System.h"
#include "llvm/ADT/SmallSet.h"
#include "Manager.h"
#include "Components.h"

extern Manager manager;

class CollisionSystem : public System {
public:
	void update();
	void render();

private:
	bool collide(RectCollider& collider_a, RectCollider& collider_b, Transform& transform_a, Transform& transform_b);
	bool collide(CircleCollider& collider_a, CircleCollider& collider_b, Transform& transform_a, Transform& transform_b);
	bool collide(Collider& collider_a, Collider& collider_b, Transform& transform_a, Transform& transform_b);
};