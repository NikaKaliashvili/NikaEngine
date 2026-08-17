#include "../../include/nika_engine.h"
#include <iostream>

static callBack onStart;
static callBack onUpdate;
static HWND _hwnd;

static void UpdateWindowBitmap(HWND hwnd) {
	GetClientRect(hwnd, &windowSize);

	if (hbMap != NULL) {
		SelectObject(hdcMem, hOldBMap);
		DeleteObject(hbMap);
		hbMap = NULL;
	}

	hbMap = CreateCompatibleBitmap(hdc, windowSize.right, windowSize.bottom);

	HBITMAP hTemp = (HBITMAP)SelectObject(hdcMem, hbMap);
	if (hOldBMap == NULL) {
		hOldBMap = hTemp;
	}
}

// this is called before actual onUpdate
static void onUpdateFunc(void*) {
	while (1) {
		onUpdate();
		InvalidateRect(_hwnd, 0, 0);
		Sleep(8); // sets fps
	}
}

static POINT cursorPos;

// main window procedure
static LRESULT WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	
	switch (msg) {

	case WM_ERASEBKGND:
		return 1;

	case WM_DESTROY:
		// properly exit
		PostQuitMessage(0);
		break;

	case WM_SIZE:
		UpdateWindowBitmap(hwnd);
		break;

	case WM_MOUSEMOVE:
		cursorPos.x = LOWORD(lParam);
		cursorPos.y = HIWORD(lParam);
		break;

	case WM_CREATE:
		// initialize globals
		hdc = GetDC(hwnd);
		hdcMem = CreateCompatibleDC(hdc);
		_hwnd = hwnd;
		UpdateWindowBitmap(hwnd);

		// call onStart function if is called
		if (onStart)
			onStart();

		// onUpdate thread
		if (onUpdate)
			_beginthread(onUpdateFunc, 0, 0);
		break;

	case WM_PAINT:
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd,&ps);

		BitBlt(hdc, 0, 0, windowSize.right, windowSize.bottom, hdcMem, 0, 0, SRCCOPY);

		EndPaint(hwnd, &ps);

		return 1;
	}


	return DefWindowProcA(hwnd, msg, wParam, lParam);

}

// initialzies main window
NikaWindow NikaEngine::InitWindow(std::string title, UINT32 x, UINT32 y, UINT32 width, UINT32 height, bool border){
	// register main window's class
	static WNDCLASSEXA wc = { 0 };
	wc.cbSize = sizeof(WNDCLASSEXA);
	wc.lpszClassName = "CLASS_NIKA";
	wc.lpfnWndProc = WndProc;
	wc.hbrBackground = NULL;

	RegisterClassExA(&wc);

	// check if window has border
	DWORD style = WS_VISIBLE;
	border ? style = style | WS_OVERLAPPEDWINDOW : style = style | WS_POPUPWINDOW;

	// create main window
	NikaWindow mainWindow = CreateWindowExA(0,"CLASS_NIKA", title.c_str(),style, x, y, width, height, 0,0,0,0);

	return mainWindow;
}

// handles window events
void NikaEngine::PollEvents() {
	static MSG msg;
	while (GetMessageA(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}
}

// sets which void should run when window is created
void NikaEngine::OnStart(callBack startCallBack)
{
	onStart = startCallBack;
}

// sets which void should run for painting
void NikaEngine::OnUpdate(callBack updateCallBack) {
	onUpdate = updateCallBack;
}

// sets cursor pos to passed point
void NikaEngine::GetCursorPos(POINT& point)
{
	point = cursorPos;
}