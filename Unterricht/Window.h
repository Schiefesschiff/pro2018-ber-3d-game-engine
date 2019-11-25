#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>

class Window
{
public:

	Window(const char* title, int width = 1280, int height = 720);
	~Window();

	bool PumpMessages();

private:

	HWND windowHandle;
	LPCSTR className;

};
