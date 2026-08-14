#include <iostream>
#include "include/nika_engine.h"

float gravity = 10;
float moveSpeed = 7;
float jumpPower = -20;
Vec2 blockPos(250, 50);
Vec2 blockSz(100, 100);
Vec2 groundPos(-1,450);
Vec2 groundSz(600,150);
COLORREF playerColor;

// runs when window is created
void start() {
	std::cout << "Game has started!" << std::endl;
	
	playerColor = RGB(255,255,255);
}

void handleGravity() {
	// handle gravity
	if (!NikaEngine::CheckCollision(blockPos, blockSz, groundPos, groundSz)) {
		gravity += 1;
	}
	else {
		gravity = 0;

		if (blockPos.y + blockSz.y > groundPos.y) {
			blockPos.y = groundPos.y - blockSz.y;
		}
	}

	blockPos.y += gravity;
}

void handleMovement() {
	// jump if space
	if (GetAsyncKeyState(VK_SPACE)) {

		if (NikaEngine::CheckCollision(blockPos, blockSz, groundPos, groundSz)) {
			blockPos.y -= 2;
			gravity = jumpPower;
		}
	}

	if (GetAsyncKeyState('A')) {
		blockPos.x -= moveSpeed;
	}
	if (GetAsyncKeyState('D')) {
		blockPos.x += moveSpeed;
	}
}

// runs 120 fps
void update() {
	// set background color to purple
	NikaEngine::SetBgColor(RGB(100, 100, 255));

	// draw ground
	NikaEngine::DrawBlock(RGB(50, 255, 50), groundPos, groundSz);

	// draw player
	NikaEngine::DrawBlock(playerColor,blockPos, blockSz);

	handleGravity(); 
	handleMovement();
	
	// change player colors
	if (GetAsyncKeyState('Q')) {
		playerColor = RGB(0,0,255);
	}

	if (GetAsyncKeyState('E')) {
		playerColor = RGB(255, 0, 0);
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