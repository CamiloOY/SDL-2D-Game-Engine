#include "Game.h"
#include "TextureManager.h"
#include "Tilemap.h"
#include "Manager.h"
#include "Components.h"
#include "RenderSystem.h"
#include "InputManager.h"
#include "MovementSystem.h"
#include "BasicEnemyAISystem.h"

SDL_Renderer* Game::renderer = nullptr;
Tilemap* tilemap;
Entity player;
Entity slime;
std::shared_ptr<RenderSystem> renderSystem;
std::shared_ptr<MovementSystem> movementSystem;
std::shared_ptr<BasicEnemyAISystem> basicEnemyAISystem;

Manager manager;
InputManager inputManager;

Game::Game() {
}

Game::~Game() {
}

void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen) {
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		int flags = 0;
		if(fullscreen) {
			flags = SDL_WINDOW_FULLSCREEN;
		}
		std::cout << "SDL successfully initialised" << std::endl;
		window = SDL_CreateWindow(title, x, y, width, height, flags);
		if(window) {
			std::cout << "Window successfully created" << std::endl;
			renderer = SDL_CreateRenderer(window, -1, 0);
			if(renderer) {
				SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
				std::cout << "Renderer successfully created" << std::endl;
				this->running = true;
				tilemap = new Tilemap();

				manager.init();
				player = manager.createEntity();
				slime = manager.createEntity();

				manager.registerComponent<Sprite>();
				manager.registerComponent<Transform>();
				manager.registerComponent<Movement>();
				manager.registerComponent<BasicEnemyAI>();

				renderSystem = manager.registerSystem<RenderSystem>();
				Signature render_system_sig;
				render_system_sig.set(manager.getComponentType<Sprite>());
				render_system_sig.set(manager.getComponentType<Transform>());
				manager.setSystemSignature<RenderSystem>(render_system_sig);

				movementSystem = manager.registerSystem<MovementSystem>();
				Signature movement_system_sig;
				movement_system_sig.set(manager.getComponentType<Transform>());
				movement_system_sig.set(manager.getComponentType<Movement>());
				manager.setSystemSignature<MovementSystem>(movement_system_sig);

				basicEnemyAISystem = manager.registerSystem<BasicEnemyAISystem>();
				Signature basic_enemy_ai_system_sig;
				basic_enemy_ai_system_sig.set(manager.getComponentType<BasicEnemyAI>());
				basic_enemy_ai_system_sig.set(manager.getComponentType<Transform>());
				manager.setSystemSignature<BasicEnemyAISystem>(basic_enemy_ai_system_sig);

				Sprite player_sprite;
				player_sprite.texture = TextureManager::LoadTexture("assets/pirate.png");
				Sprite slime_sprite;
				slime_sprite.texture = TextureManager::LoadTexture("assets/slime.png");
				Transform player_transform = {{33, 33}};
				Transform slime_transform = {{400, 99}, {4, 4}};
				Movement player_movement = {3};
				BasicEnemyAI slime_ai = {1, 1, 100};

				manager.addComponent<Sprite>(player, player_sprite);
				manager.addComponent<Transform>(player, player_transform);
				manager.addComponent<Movement>(player, player_movement);
				manager.addComponent<Sprite>(slime, slime_sprite);
				manager.addComponent<Transform>(slime, slime_transform);
				manager.addComponent<BasicEnemyAI>(slime, slime_ai);
			}
		}
	}
}

void Game::handleEvents() {
	SDL_Event e;
	SDL_PollEvent(&e);
	switch(e.type) {
		case SDL_QUIT:
			this->running = false;
			break;
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			inputManager.handleEvent(&e);
			break;
		default:
			break;
	}
}

void Game::update() {
	movementSystem->update();
	basicEnemyAISystem->update();
}

void Game::render() {
	SDL_RenderClear(this->renderer);
	tilemap->drawTilemap();
	renderSystem->render();
	SDL_RenderPresent(this->renderer);
}

void Game::clean() {
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}

bool Game::isRunning() {
	return this->running;
}
