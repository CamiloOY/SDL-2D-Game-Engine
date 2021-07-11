#pragma once

#include <SDL.h>
#include "Types.h"
#include <string>
#include <llvm/ADT/SmallSet.h>

struct Sprite {
	SDL_Texture* texture;
};

struct Transform {
	Vec2 position = {0, 0};
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
};

struct RectCollider {
	int relative_x = 0;
	int relative_y = 0;
	int w;
	int h;
	std::string tag;
	bool draw_bounding_box = false;
	llvm::SmallDenseSet<Entity, 8> collisions;
};