#include "InputManager.h"

InputManager::InputManager() {
	key_to_command[SDL_GetKeyFromName("A")] = Command::MOVE_LEFT;
	key_to_command[SDL_GetKeyFromName("D")] = Command::MOVE_RIGHT;
	key_to_command[SDL_GetKeyFromName("W")] = Command::MOVE_UP;
	key_to_command[SDL_GetKeyFromName("S")] = Command::MOVE_DOWN;
}

void InputManager::receiveEvent(SDL_Event* e) {
	switch(e->type) {
	case SDL_KEYDOWN:
		commands[static_cast<unsigned short>(key_to_command.lookup((SDL_KeyCode&) e->key.keysym.sym))] = true;
		break;
	case SDL_KEYUP:
		commands[static_cast<unsigned short>(key_to_command.lookup((SDL_KeyCode&) e->key.keysym.sym))] = false;
		break;
	default:
		break;
	}
}

SDL_Event& InputManager::getEvent() {
	return e;
}

bool InputManager::getCommand(Command c) {
	return commands[static_cast<unsigned short>(c)];
}
