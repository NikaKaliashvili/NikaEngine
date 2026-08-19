#define nika_pi 3.14159265

#include "include/nika_engine.h"

using namespace NikaEngine;

static POINT cursorPos;
static POINT previousCursorPos;
static POINT center;

Vec3 playerPos, movement, forward, right;
Vec3 worldUp = {0,1,0}, cameraPosition, cameraForward, cameraRight, cameraUp;
float yaw, pitch, yawRad, pitchRad;
float moveSpeed = 3, sensitivity = 0.1f;
float deltaTime;

std::chrono::steady_clock::time_point previousTime, currentTime;

static void start() {
	previousTime = std::chrono::steady_clock::now(); // reset previousTime
	cameraPosition = Vec3(playerPos.x, playerPos.y + 1.5f, playerPos.z); // set camera starting position
	NikaEngine::GetCursorPos(previousCursorPos); // get cursor starting position
}

bool lockCursor = false;

// runs 120 fps
static void update() {
	// set background color to purple
	SetBgColor(RGB(100, 100, 255));

	// get current time
	currentTime = std::chrono::steady_clock::now(); 

	deltaTime = std::chrono::duration<float>(currentTime - previousTime).count();

	// set previousTime to currentTime
	previousTime = currentTime; 

	// get half of width and height
	center = {(windowSize.right) / 2, (windowSize.bottom) / 2};

	// add window position
	ClientToScreen(_hwnd, &center);

	// get current cursor position
	NikaEngine::GetCursorPos(cursorPos);

	// lock cursor to center if lockCursor is true
	if (lockCursor)
		SetCursorPos(center.x, center.y);

	// add mouse movement to yaw and pitch
	yaw += (cursorPos.x - previousCursorPos.x) * sensitivity;
	pitch -= (cursorPos.y - previousCursorPos.y) * sensitivity;

	// reset previousCursorPos
	previousCursorPos = cursorPos;

	// lock camera Y to -89 -> 89 max
	if (pitch > 89.0f)
		pitch = 89.0f;

	if (pitch < -89.0f)
		pitch = -89.0f;


	// turn degree to radians
	yawRad = yaw * nika_pi / 180;
	pitchRad = pitch * nika_pi / 180;

	// calculate movement forward direction
	forward = { sin(yawRad),0,cos(yawRad) };

	// calculate movement right direction
	right = { cos(yawRad),0, -sin(yawRad) };

	// calculate camera forward direction
	cameraForward = { cos(pitchRad) * sin(yawRad) , sin(pitchRad), cos(pitchRad) * cos(yawRad) };

	// calculate camera right direction
	cameraRight = worldUp.cross(cameraForward);
	cameraRight.normalize();

	// calculate camera up direction
	cameraUp = cameraForward.cross(cameraRight);
	cameraUp.normalize();

	// reset movement
	movement = { 0,0,0 };

	if (GetAsyncKeyState('W'))
		movement += forward;

	if (GetAsyncKeyState('S'))
		movement -= forward;

	if (GetAsyncKeyState('A'))
		movement -= right;

	if (GetAsyncKeyState('D'))
		movement += right;

	if (GetAsyncKeyState('E'))
		lockCursor = !lockCursor;

	if (GetAsyncKeyState('Q'))
		exit(1);

	if (movement.magnitude() > 0.0f) {
		movement = movement.normalize();
	}

	// change player position
	playerPos = playerPos + movement * moveSpeed * deltaTime;

	std::cout << cameraRight << std::endl;

	// NOTE: temporary to see logs
	Sleep(400);
}

int main() {
	// runs 'start' void when window is created
	OnStart(start);

	// runs 'update' void on paint
	OnUpdate(update);

	// initialize window
	NikaWindow Game = InitWindow("Game test", 100,100,600,600,true);

	// handle window events
	PollEvents();

	return 0;
}