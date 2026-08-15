#pragma once

#include "../nika_engine.h"

namespace NikaEngine {
	// Checks collisions between two entites
	bool CheckCollision(Vec2& entityPos, Vec2& entitySz, Vec2& entity2Pos, Vec2& entity2Sz);
	
	// Checks collisions between two NIKA entities
	bool CheckCollision_N(NikaObject& entity, NikaObject& entity2);
};