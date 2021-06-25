#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* player;

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
				player = new GameObject("assets/pirate.png", this->renderer);
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
	player->update();
}

void Game::render() {
	SDL_RenderClear(this->renderer);
	player->render();
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
