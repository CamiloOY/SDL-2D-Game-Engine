#pragma once

#include "TextureManager.h"

class GameObject {

public:
	GameObject(const char* texture_sheet, SDL_Renderer* renderer, int x = 0, int y = 0);
	~GameObject();
	void update();
	void render();

private:
	int x;
	int y;
	SDL_Texture* texture;
	SDL_Rect source_rectangle, destination_rectangle;
	SDL_Renderer* renderer;
};

