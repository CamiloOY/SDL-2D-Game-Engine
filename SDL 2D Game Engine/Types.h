#pragma once

#include <cstdint>
#include <bitset>

using ComponentType = std::uint8_t;
const ComponentType MAX_COMPONENTS = 64;
using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 8192;
using Signature = std::bitset<MAX_COMPONENTS>;

struct Vec2 {
	int x;
	int y;
};

struct Vec2f {
	float x;
	float y;
};

// A command is a number representing an action that can the player can trigger
enum class Command : uint8_t {
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_UP,
	MOVE_DOWN
};

enum class ColliderType : uint8_t {
	Rect,
	Circle
};