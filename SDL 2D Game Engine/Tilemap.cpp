#include "Tilemap.h"
#include "TextureManager.h"

Tilemap::Tilemap() {
	this->dirt = TextureManager::LoadTexture("assets/dirt.png");
	this->grass = TextureManager::LoadTexture("assets/grass.png");
	int default_map[20][25];
	for(int c = 0; c < 20; c++) {
		for(int i = 0; i < 25; i++) {
			default_map[c][i] = 1;
		}
	}
	this->loadTilemap(default_map);

	this->source_rectangle.x = 0;
	this->source_rectangle.y = 0;

	this->source_rectangle.w = 32;
	this->source_rectangle.h = 32;

	this->destination_rectangle.x = 0;
	this->destination_rectangle.y = 0;

	this->destination_rectangle.w = 32;
	this->destination_rectangle.h = 32;
}

void Tilemap::loadTilemap(int tilemap[20][25]) {
	for(int j = 0; j < 20; j++) {
		for(int k = 0; k < 25; k++) {
			this->tilemap[j][k] = tilemap[j][k];
		}
	}
}

void Tilemap::drawTilemap() {
	for(int l = 0; l < 20; l++) {
		for(int m = 0; m < 25; m++) {
			this->destination_rectangle.x = m * 32;
			this->destination_rectangle.y = l * 32;
			switch(this->tilemap[l][m]) {
			case 0:
				TextureManager::DrawTexture(this->grass, this->source_rectangle, this->destination_rectangle);
				break;
			case 1:
				TextureManager::DrawTexture(this->dirt, this->source_rectangle, this->destination_rectangle);
				break;
			default:
				break;
			}
		}
	}
}
