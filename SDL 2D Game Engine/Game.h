#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
//#include <SDL_image.h>

class Game {
public:
	Game();
	~Game();
	void init(const char* title, int x, int y, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool isRunning();

private:
	bool running = false;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

