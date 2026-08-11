#pragma once

#include "../NikaEngine.h"

namespace NikaEngine {
	
	NikaWindow InitWindow(std::string title, UINT32 x, UINT32 y, UINT32 width, UINT32 height, bool border, COLORREF bgColor);
	void PollEvents();
}