#include "../../include/nika_engine.h"


// checks collision between entity and ground
bool NikaEngine::CheckCollision(Vec2& entityPos, Vec2& entitySz, Vec2& groundPos, Vec2& groundSz) {
	if (entityPos.y + entitySz.y < groundPos.y)
		return false;

	if (entityPos.y > groundPos.y + groundSz.y)
		return false;

	if (entityPos.x + entitySz.x < groundPos.x)
		return false;

	if (entityPos.x > groundPos.x + groundSz.x)
		return false;

	return true;
}