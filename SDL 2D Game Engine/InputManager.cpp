#include "InputManager.h"

InputManager::InputManager() {
	key_to_command[SDL_GetKeyFromName("A")] = Command::MOVE_LEFT;
	key_to_command[SDL_GetKeyFromName("D")] = Command::MOVE_RIGHT;
	key_to_command[SDL_GetKeyFromName("W")] = Command::MOVE_UP;
	key_to_command[SDL_GetKeyFromName("S")] = Command::MOVE_DOWN;
}

void InputManager::handleEvent(SDL_Event* e) {
	switch(e->type) {
	case SDL_KEYDOWN:
		if(key_to_command.count((SDL_KeyCode&) e->key.keysym.sym)) {
			commands[static_cast<uint8_t>(key_to_command.lookup((SDL_KeyCode&) e->key.keysym.sym))] = true;
		}
		break;
	case SDL_KEYUP:
		if(key_to_command.count((SDL_KeyCode&) e->key.keysym.sym)) {
			commands[static_cast<uint8_t>(key_to_command.lookup((SDL_KeyCode&) e->key.keysym.sym))] = false;
		}
		break;
	default:
		break;
	}
}

SDL_Event& InputManager::getEvent() {
	return e;
}

bool InputManager::getCommand(Command c) {
	return commands[static_cast<uint8_t>(c)];
}

void InputManager::setKeyCommand(SDL_Keycode key, Command command) {
	key_to_command[key] = command;
}
