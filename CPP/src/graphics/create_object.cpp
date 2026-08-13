#include "../../include/nika_engine.h"

static RECT rect = { 0,0,600,600 };

// Set window background color
void NikaEngine::SetBgColor(COLORREF bgColor) {
	HBRUSH brush = CreateSolidBrush(bgColor);
	FillRect(hdcMem, &rect, brush);
	DeleteObject(brush);
}

// Create rectangle
void NikaEngine::DrawBlock(COLORREF bodyColor, Vec2 pos, Vec2 sz) {
	HBRUSH hBrush = CreateSolidBrush(bodyColor);
	SelectObject(hdcMem, hBrush);
	Rectangle(hdcMem, pos.x, pos.y, sz.x+pos.x, sz.y+pos.y);
	DeleteObject(hBrush);
}