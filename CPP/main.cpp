#include <iostream>
#include "include/nika_engine.h"

Vec2 blockPos(250, 50);

// runs when window is created
void start() {
	std::cout << "Game has started!" << std::endl;
}

// runs 120 fps
void update() {
	// set background color to purple
	NikaEngine::SetBgColor(RGB(100, 100, 255));

	// create white block on the screen
	NikaEngine::DrawBlock(RGB(255,255,255),blockPos, Vec2(100, 100));

	// block movement

	if (GetAsyncKeyState('W')) {
		blockPos.y -= 5;
	}

	if (GetAsyncKeyState('S')) {
		blockPos.y += 5;
	}

	if (GetAsyncKeyState('A')) {
		blockPos.x -= 5;
	}

	if (GetAsyncKeyState('D')) {
		blockPos.x += 5;
	}
}

int main() {

	// runs 'start' void when window is created
	NikaEngine::OnStart(start);

	// runs 'update' void on paint
	NikaEngine::OnUpdate(update);

	// initialize window
	NikaWindow Game = NikaEngine::InitWindow("Game test", 100,100,600,600,true);

	// testing vectors
	Vec2 a(5, 5);
	Vec2 b(10, 10);
	Vec2 c = a + b;

	// handle window events
	NikaEngine::PollEvents();

	return 0;
}