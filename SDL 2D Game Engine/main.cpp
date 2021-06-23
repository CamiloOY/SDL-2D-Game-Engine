#include "Game.h"

int main() {
	Game* game = new Game();
	game->init("SDL Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	while(game->isRunning()) {
		game->handleEvents();
		game->update();
		game->render();
	}
	game->clean();
	return 0;
}