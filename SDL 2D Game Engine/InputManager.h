#pragma once
#include <SDL_events.h>
#include "Types.h"
#include <llvm/ADT/DenseMap.h>

class InputManager {
public:
	InputManager();
	void handleEvent(SDL_Event* e); // Handles a keyboard event
	SDL_Event& getEvent(); // Returns the current event object
	bool getCommand(Command c); // Gets whether the provided command is active
	void setKeyCommand(SDL_Keycode key, Command command); // Changes the command a key performs

private:
	SDL_Event e;
	bool commands[128] = {false}; // An array mapping each command to whether it is active
	llvm::DenseMap<SDL_Keycode, Command> key_to_command; // Maps a key to a command
};