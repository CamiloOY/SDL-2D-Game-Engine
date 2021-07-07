#pragma once
#include <SDL_events.h>
#include "Types.h"
#include <llvm/ADT/DenseMap.h>

class InputManager {
public:
	InputManager();
	void receiveEvent(SDL_Event* e);
	SDL_Event& getEvent();
	bool getCommand(Command c);

private:
	SDL_Event e;
	bool commands[128] = {false};
	llvm::DenseMap<SDL_Keycode, Command> key_to_command;
};