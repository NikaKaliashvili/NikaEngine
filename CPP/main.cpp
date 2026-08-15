#include <iostream>
#include "include/nika_engine.h"

using namespace NikaEngine;

float gravity = 10;
float moveSpeed = 7;
float jumpPower = -20;

NikaObject player = {RGB(255,255,255), Vec2(250,50), Vec2(100,100)};
NikaObject ground = {RGB(50, 255, 50), Vec2(-1,450), Vec2(800,150)};
NikaObject enemy = {RGB(255, 50, 50), Vec2(500,400), Vec2(50,50)};

// runs when window is created
static void start() {
	std::cout << "Game has started!" << std::endl;
}

static void handleGravity() {
	// handle gravity
	if (!CheckCollision_N(player, ground)) {
		gravity += 1;
	}
	else {
		gravity = 0;

		if (player.pos.y + player.sz.y > ground.pos.y) {
			player.pos.y = ground.pos.y - player.sz.y;
		}
	}

	player.pos.y += gravity;
}

static void handleMovement() {
	// jump if space
	if (GetAsyncKeyState(VK_SPACE)) {

		if (CheckCollision(player.pos, player.sz, ground.pos, ground.sz)) {
			player.pos.y -= 2;
			gravity = jumpPower;
		}
	}

	if (GetAsyncKeyState('A')) {
		player.pos.x -= moveSpeed;
	}
	if (GetAsyncKeyState('D')) {
		player.pos.x += moveSpeed;
	}
}

// runs 120 fps
static void update() {
	// set background color to purple
	SetBgColor(RGB(100, 100, 255));

	// draw ground
	DrawBlock(ground.bodyColor, ground.pos, ground.sz);

	// draw player
	DrawBlock(player.bodyColor,player.pos, player.sz);

	// draw enemy
	DrawBlock(enemy.bodyColor, enemy.pos, enemy.sz);

	// draw circle
	DrawEllipse(RGB(155,25,200), Vec2(50,150), Vec2(100,100));

	// draw triangle
	DrawTriangle(RGB(255,255,0), Vec2(50,50), Vec2(100,100));

	handleGravity(); 
	handleMovement();

	// check collision with enemy

	if (CheckCollision_N(player, enemy)) {
		player.pos = Vec2(250,50);
		std::cout << "You died!" << std::endl;
	}
}

int main() {

	// runs 'start' void when window is created
	OnStart(start);

	// runs 'update' void on paint
	OnUpdate(update);

	// initialize window
	NikaWindow Game = InitWindow("Game test", 100,100,600,600,true);

	// testing vectors
	Vec2 a(5, 5);
	Vec2 b(10, 10);
	Vec2 c = a + b;

	// handle window events
	PollEvents();

	return 0;
}