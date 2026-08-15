#include "../../include/nika_engine.h"

// Set window background color
void NikaEngine::SetBgColor(COLORREF bgColor) {
	HBRUSH hBrush = CreateSolidBrush(bgColor);

	// NOTE TO MYSELF: CHANGE THIS LATER!
	FillRect(hdcMem, &windowSize, hBrush);

	DeleteObject(hBrush);
}

// Create rectangle
void NikaEngine::DrawBlock(COLORREF bodyColor, Vec2 pos, Vec2 sz) {
	HBRUSH hBrush = CreateSolidBrush(bodyColor);
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdcMem, hBrush);

	Rectangle(hdcMem, pos.x, pos.y, sz.x+pos.x, sz.y+pos.y);
	
	SelectObject(hdcMem, hOldBrush);
	DeleteObject(hBrush);
}

// Create ellipse
void NikaEngine::DrawEllipse(COLORREF bodyColor, Vec2 pos, Vec2 sz)
{
	HBRUSH hBrush = CreateSolidBrush(bodyColor);
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdcMem, hBrush);

	Ellipse(hdcMem, pos.x, pos.y, sz.x + pos.x, sz.y + pos.y);

	SelectObject(hdcMem, hOldBrush);
	DeleteObject(hBrush);
}

// Create triangle
void NikaEngine::DrawTriangle(COLORREF bodyColor, Vec2 pos, Vec2 sz)
{
	POINT verticies[] = {
		{pos.x, pos.y + sz.y },
		{pos.x + sz.x / 2, pos.y},
		{pos.x + sz.x, pos.y + sz.y}
	};

	HBRUSH hBrush = CreateSolidBrush(bodyColor);
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hdcMem, hBrush);
	
	Polygon(hdcMem, verticies , 3);
	
	SelectObject(hdcMem, hOldBrush);
	DeleteObject(hBrush);
}

