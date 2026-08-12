#include "../../include/nika_engine.h"

static callBack onStart;
static callBack onUpdate;

// main window procedure
static LRESULT WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	
	switch (msg) {

	case WM_DESTROY:
		// properly exit
		PostQuitMessage(0);
		break;

	case WM_CREATE:
		// call onStart function if is called
		if (onStart)
			onStart();
		break;

	case WM_PAINT:
		// call onUpdate function if is called
		if (onUpdate)
			onUpdate();
		break;
	}

	return DefWindowProcA(hwnd, msg, wParam, lParam);

}

// initialzies main window
NikaWindow NikaEngine::InitWindow(std::string title, UINT32 x, UINT32 y, UINT32 width, UINT32 height, bool border, COLORREF bgColor){
	// register main window's class
	static WNDCLASSEXA wc = { 0 };
	wc.cbSize = sizeof(WNDCLASSEXA);
	wc.lpszClassName = "CLASS_NIKA";
	wc.lpfnWndProc = WndProc;
	wc.hbrBackground = CreateSolidBrush(bgColor);
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