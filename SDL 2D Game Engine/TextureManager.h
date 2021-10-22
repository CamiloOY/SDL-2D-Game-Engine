#pragma once

#include "Game.h"
#include <SDL_image.h>

class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* filename); // Create a texture on the heap
	static void DrawTexture(SDL_Texture* texture, SDL_Rect source_rect, SDL_Rect destination_rect); // Draw a texture
};

