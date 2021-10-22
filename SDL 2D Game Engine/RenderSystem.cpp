#include "RenderSystem.h"
#include <SDL.h>
#include "Components.h"
#include "Game.h"

void RenderSystem::render() {
	for(Entity& entity : entities) {
		int w, h;
		Sprite& sprite = manager.getComponent<Sprite>(entity); // Used for the entity's texture
		Transform& transform = manager.getComponent<Transform>(entity);
		SDL_Rect source_rect, dest_rect;
		SDL_QueryTexture(sprite.texture, nullptr, nullptr, &source_rect.w, &source_rect.h);
		source_rect.x = 0; // Read the texture from the top-left corner
		source_rect.y = 0;

		// Create the destination rectangle for the texture to be drawn onto
		dest_rect.x = transform.position.x;
		dest_rect.y = transform.position.y;
		dest_rect.w = source_rect.w * transform.scale.x;
		dest_rect.h = source_rect.h * transform.scale.y;
		SDL_RenderCopy(Game::renderer, sprite.texture, &source_rect, &dest_rect); // Draw the texture
	}
}