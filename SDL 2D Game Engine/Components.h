#pragma once

#include <SDL.h>
#include "Types.h"

typedef struct Sprite {
	SDL_Texture* texture;
} Sprite;

typedef struct Transform {
	Vec2 position = {0, 0};
	Vec2 scale = {1, 1};
} Transform;