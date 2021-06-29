#pragma once

#include "Game.h"

class Tilemap {
public:
	Tilemap();
	~Tilemap();
	void loadTilemap(int tilemap[20][25]);
	void drawTilemap();

private:
	SDL_Rect source_rectangle, destination_rectangle;
	SDL_Texture* grass;
	SDL_Texture* dirt;
	int tilemap[20][25];
};

