#include "Game.h"

int main() {
	const int frame_rate = 144;
	const int frame_delay = 1000 / frame_rate; //How long each frame should take in milliseconds
	Uint32 frame_start;
	int frame_time;
	Game* game = new Game();
	game->init("SDL Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
	while(game->isRunning()) {
		frame_start = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();
		frame_time = SDL_GetTicks() - frame_start; //How long this frame took to process
		if(frame_delay > frame_time) { //If this frame was faster than necessary, delay the frame
			SDL_Delay(frame_delay - frame_time);
		}
	}
	game->clean();
	return 0;
}