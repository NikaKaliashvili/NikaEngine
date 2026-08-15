#pragma once

#include "../nika_engine.h"

namespace NikaEngine {

	// Sets the color of window background
	void SetBgColor(COLORREF bgColor);

	// Draws rectangle on the screen with specified color
	void DrawBlock(COLORREF bodyColor, Vec2 pos, Vec2 sz);

	// Draws ellipse on the screen with specified color
	void DrawEllipse(COLORREF bodyColor, Vec2 pos, Vec2 sz);

	// Draws triangle on the screen with specified color
	void DrawTriangle(COLORREF bodyColor, Vec2 pos, Vec2 sz);
}