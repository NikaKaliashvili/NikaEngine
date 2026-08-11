#include <iostream>
#include "include/NikaEngine.h"

int main() {

	NikaWindow Game = NikaEngine::InitWindow("Game test", 100,100,600,600,true,RGB(100,100,255));

	Vec2 a(5, 5);
	Vec2 b(10, 10);
	Vec2 c = a + b;

	NikaEngine::PollEvents();

	return 0;
}