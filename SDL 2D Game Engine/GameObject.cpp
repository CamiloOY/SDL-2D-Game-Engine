#include "GameObject.h"
#include <iostream>

GameObject::GameObject(const char* texture, int x, int y) {
	this->texture = TextureManager::LoadTexture(texture);
	this->x = x;
	this->y = y;

}

void GameObject::update() {
	int w, h;
	SDL_QueryTexture(this->texture, nullptr, nullptr, &w, &h);

	this->x++;
	this->y++;

	this->source_rectangle.w = w;
	this->source_rectangle.h = h;
	this->source_rectangle.x = 0;
	this->source_rectangle.y = 0;

	this->destination_rectangle.x = this->x;
	this->destination_rectangle.y = this->y;
	this->destination_rectangle.w = this->source_rectangle.w;
	this->destination_rectangle.h = this->source_rectangle.h;
}

void GameObject::render() {
	SDL_RenderCopy(Game::renderer, this->texture, &this->source_rectangle, &this->destination_rectangle);
}
