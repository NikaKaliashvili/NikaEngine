#include "../../include/nika_engine.h"


// checks collision between entity pos & sz and entity2 pos & sz
bool NikaEngine::CheckCollision(Vec2& entityPos, Vec2& entitySz, Vec2& entity2Pos, Vec2& entity2Sz) {
	if (entityPos.y + entitySz.y < entity2Pos.y)
		return false;

	if (entityPos.y > entity2Pos.y + entity2Sz.y)
		return false;

	if (entityPos.x + entitySz.x < entity2Pos.x)
		return false;

	if (entityPos.x > entity2Pos.x + entity2Sz.x)
		return false;

	return true;
}

// checks collision between two nika entities
bool NikaEngine::CheckCollision_N(NikaObject& entity, NikaObject& entity2)
{
	if (entity.pos.y + entity.sz.y < entity2.pos.y)
		return false;

	if (entity.pos.y > entity2.pos.y + entity2.sz.y)
		return false;

	if (entity.pos.x + entity.sz.x < entity2.pos.x)
		return false;

	if (entity.pos.x > entity2.pos.x + entity2.sz.x)
		return false;

	return true;
}
