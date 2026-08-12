#include <iostream>
#include "include/nika_engine.h"

void start() {
	std::cout << "Hello World" << std::endl;
}

void update() {
	std::cout << "Window is running" << std::endl;
}

int main() {

	// runs 'start' void when window is created
	NikaEngine::OnStart(start);

	// runs 'update' void on paint
	NikaEngine::OnUpdate(update);

	// initialize window
	NikaWindow Game = NikaEngine::InitWindow("Game test", 100,100,600,600,true,RGB(100,100,255));

	// testing vectors
	Vec2 a(5, 5);
	Vec2 b(10, 10);
	Vec2 c = a + b;

	// handle window events
	NikaEngine::PollEvents();

	return 0;
}