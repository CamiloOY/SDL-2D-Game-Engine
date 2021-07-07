#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Tilemap.h"
#include "Manager.h"
#include "Components.h"
#include "RenderSystem.h"

//GameObject* player;
SDL_Renderer* Game::renderer = nullptr;
Tilemap* tilemap;
Entity playr;

Manager manager;

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
				//player = new GameObject("assets/pirate.png");
				tilemap = new Tilemap();
				manager.init();
				playr = manager.createEntity();
				manager.registerComponent<Sprite>();
				manager.registerComponent<Transform>();
				auto renderSystem = manager.registerSystem<RenderSystem>();
				Signature render_system_sig;
				render_system_sig.set(manager.getComponentType<Sprite>());
				render_system_sig.set(manager.getComponentType<Transform>());
				manager.setSystemSignature<RenderSystem>(render_system_sig);
				Sprite player_sprite;
				player_sprite.texture = TextureManager::LoadTexture("assets/pirate.png");
				Transform player_transform = {{33, 33}};
				manager.addComponent<Sprite>(playr, player_sprite);
				manager.addComponent<Transform>(playr, player_transform);
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
		default:
			break;
	}
}

void Game::update() {
	//player->update();
	manager.update();
}

void Game::render() {
	SDL_RenderClear(this->renderer);
	tilemap->drawTilemap();
	//player->render();
	manager.render();
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
