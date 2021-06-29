#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* filename) {
	SDL_Surface* temp_surface = IMG_Load(filename);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, temp_surface);
	SDL_FreeSurface(temp_surface);
	return texture;
}

void TextureManager::DrawTexture(SDL_Texture* texture, SDL_Rect source_rect, SDL_Rect destination_rect) {
	SDL_RenderCopy(Game::renderer, texture, &source_rect, &destination_rect);
}
