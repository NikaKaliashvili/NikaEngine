#pragma once

#include "../nika_engine.h"

namespace NikaEngine {
	// initializes main window
	NikaWindow InitWindow(std::string title, UINT32 x, UINT32 y, UINT32 width, UINT32 height, bool border);
	
	/*
	Handles window events.
	NOTE: this must be called AFTER InitWindow function.
	also, this function uses WHILE loop. so anything below this wont be called!
	*/
	void PollEvents();

	/* 
	Calls startCallBack void when window is created.
	NOTE: this must be called BEFORE InitWindow function.
	*/
	void OnStart(callBack startCallBack);

	/*
	Calls updateCallBack void during painting.
	NOTE: this must be called BEFORE InitWindow function.
	*/
	void OnUpdate(callBack updateCallBack);

	// retrieves cursor position
	void GetCursorPos(POINT& point);
}