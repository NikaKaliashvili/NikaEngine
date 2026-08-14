#pragma once

#include "../nika_engine.h"

namespace NikaEngine {
	bool CheckCollision(Vec2& entityPos, Vec2& entitySz, Vec2& groundPos, Vec2& groundSz);
}