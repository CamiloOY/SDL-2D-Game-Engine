#pragma once

#include <SDL.h>
#include "Types.h"
#include <string>
#include <llvm/ADT/SmallSet.h>

struct Sprite {
	SDL_Texture* texture;
};

struct Transform {
	Vec2f position = {0, 0};
	Vec2f scale = {1, 1};
};

struct Movement {
	float speed = 1;
};

struct BasicEnemyAI {
	int direction = 1;
	float speed = 1;
	int distance = 50;
	int travelled = 0;
	bool angered = false;
	Entity target;
};

struct RectCollider {
	// The position of the collider relative to the entity's transform
	int relative_x = 0;
	int relative_y = 0;

	// The size of the bounding box
	int w;
	int h;

	std::string tag; // A tag describing the collider
	bool draw_bounding_box = false; // Whether the bounding box should be drawn (for debug purposes)
	llvm::SmallDenseSet<Entity, 8> collisions;
};