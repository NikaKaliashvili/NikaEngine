#include "include/nika_engine.h"

using namespace NikaEngine;

static POINT cursorPos;

// runs 120 fps
static void update() {
	// set background color to purple
	SetBgColor(RGB(100, 100, 255));
	GetCursorPos(cursorPos);
}

int main() {
	// runs 'start' void when window is created
	//OnStart(start);

	// runs 'update' void on paint
	OnUpdate(update);

	// initialize window
	NikaWindow Game = InitWindow("Game test", 100,100,600,600,true);

	// handle window events
	PollEvents();

	return 0;
}