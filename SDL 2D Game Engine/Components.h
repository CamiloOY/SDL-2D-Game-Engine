#pragma once

#include <SDL.h>
#include "Types.h"

struct Sprite {
	SDL_Texture* texture;
};

struct Transform {
	Vec2 position = {0, 0};
	Vec2 scale = {1, 1};
};

struct Movement {
	int speed = 1;
};