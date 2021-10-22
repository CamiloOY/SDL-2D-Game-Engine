#pragma once

#include <cstdint>
#include <bitset>
#include <cmath>

using ComponentType = std::uint8_t;
const ComponentType MAX_COMPONENTS = 64;
using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 8192;
using Signature = std::bitset<MAX_COMPONENTS>;

class Vec2 {
public:
	int x;
	int y;

	friend Vec2 operator-(Vec2 left, Vec2 right) {
		return {left.x - right.x, left.y - right.y};
	}
	friend Vec2 operator+(Vec2 left, Vec2 right) {
		return {left.x + right.x, left.y + right.y};
	}
};

class Vec2f {
public:
	float x;
	float y;

	/*
	* Normalises the magnitude of the vector to 1 (while keeping the same direction)
	*/
	void normalise() {
		float divisor = sqrt(pow(x, 2) + pow(y, 2));
		x /= divisor;
		y /= divisor;
	}

	friend Vec2f operator-(Vec2f left, Vec2f right) {
		return {left.x - right.x, left.y - right.y};
	}
	friend Vec2f operator+(Vec2f left, Vec2f right) {
		return {left.x + right.x, left.y + right.y};
	}
};

// A command is a number representing an action that can the player can trigger
enum class Command : uint8_t {
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_UP,
	MOVE_DOWN
};