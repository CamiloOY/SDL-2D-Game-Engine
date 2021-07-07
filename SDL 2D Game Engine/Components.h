#pragma once

#include <SDL.h>
#include "Types.h"

struct Sprite {
	SDL_Texture* texture;
};

struct Transform {
	Vec2 position = {0, 0};
	Vec2f scale = {1, 1};
};

struct Movement {
	int speed = 1;
};

struct BasicEnemyAI {
	int direction = 1;
	float speed = 1;
	int distance = 50;
	int travelled = 0;
};