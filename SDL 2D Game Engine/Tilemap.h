#pragma once

#include "Game.h"

class Tilemap {
public:
	Tilemap();
	~Tilemap();
	void loadTilemap(int tilemap[20][25]); // Loads a tilemap to be drawn
	void drawTilemap(); // Draws a 20x25 tilemap

private:
	SDL_Rect source_rectangle, destination_rectangle;
	SDL_Texture* grass;
	SDL_Texture* dirt;
	int tilemap[20][25];
};

