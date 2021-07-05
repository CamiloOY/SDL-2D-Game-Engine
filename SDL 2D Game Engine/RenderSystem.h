#pragma once

#include "System.h"
#include "Manager.h"

extern Manager manager;

class RenderSystem : public System {
public:
	void render();
};