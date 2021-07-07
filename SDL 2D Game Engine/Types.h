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