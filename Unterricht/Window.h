#pragma once

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>

class Window
{
public:

	~Window();

	void Initialize(const char* title, int width = 1280, int height = 720);
	void Show(bool show);
	bool PumpMessages();

	inline int GetWidth(void) const { return this->wWidth; };
	inline int GetHeight(void) const { return this->wHeight; };
	inline HWND GetHandle(void) const { return this->windowHandle; };

private:

	HWND windowHandle;
	LPCSTR className;
	int wWidth;
	int wHeight;
};
