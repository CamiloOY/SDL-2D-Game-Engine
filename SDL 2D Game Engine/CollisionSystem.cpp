#include "CollisionSystem.h"
#include "Components.h"
#include "Game.h"

void CollisionSystem::update() {
	for(Entity& entity_a : entities) {
		RectCollider& collider_a = manager.getComponent<RectCollider>(entity_a);
		collider_a.collisions.clear();
		Transform& transform_a = manager.getComponent<Transform>(entity_a);
		for(Entity& entity_b : entities) {
			if(entity_a == entity_b) {
				continue;
			}
			RectCollider& collider_b = manager.getComponent<RectCollider>(entity_b);
			Transform& transform_b = manager.getComponent<Transform>(entity_b);
			float rect_a_x = transform_a.position.x + collider_a.relative_x;
			float rect_a_y = transform_a.position.y + collider_a.relative_y;
			float rect_b_x = transform_b.position.x + collider_b.relative_x;
			float rect_b_y = transform_b.position.y + collider_b.relative_y;
			if(rect_a_x < rect_b_x + collider_b.w && rect_a_x + collider_a.w > rect_b_x && rect_a_y < rect_b_y + collider_b.h && rect_a_y + collider_a.h > rect_b_y) {
				collider_a.collisions.insert(entity_b);
			}
		}
	}
}

//TODO: Optimise this
void CollisionSystem::render() {
	for(Entity& entity : entities) {
		RectCollider& collider = manager.getComponent<RectCollider>(entity);
		if(collider.draw_bounding_box) {
			Transform& transform = manager.getComponent<Transform>(entity);
			float rect_x = transform.position.x + collider.relative_x;
			float rect_y = transform.position.y + collider.relative_y;
			SDL_RenderDrawLine(Game::renderer, rect_x, rect_y, rect_x + collider.w, rect_y);
			SDL_RenderDrawLine(Game::renderer, rect_x, rect_y, rect_x, rect_y + collider.h);
			SDL_RenderDrawLine(Game::renderer, rect_x + collider.w, rect_y, rect_x + collider.w, rect_y + collider.h);
			SDL_RenderDrawLine(Game::renderer, rect_x, rect_y + collider.h, rect_x + collider.w, rect_y + collider.h);
		}
	}
}