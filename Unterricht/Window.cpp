#include <stdlib.h>
#include <stdio.h>

#include "Window.h"

LRESULT WINAPI WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_CLOSE:
			DestroyWindow(hWnd);
			break;

		case WM_DESTROY:
			PostQuitMessage(EXIT_SUCCESS);
			break;

		default:
			return DefWindowProcA(
				hWnd,
				uMsg,
				wParam,
				lParam
			);
	}
}

Window::Window(const char* title, int width, int height)
{
	WNDCLASSEXA wc = { };
	wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpszClassName = title;
	wc.lpfnWndProc = WndProc;

	this->className = wc.lpszClassName;

	if (FAILED(RegisterClassEx(&wc)))
	{

	}

	DWORD style = WS_OVERLAPPEDWINDOW;
	this->windowHandle = CreateWindowEx(
		0,
		wc.lpszClassName,
		title,
		style,
		0,
		0,
		width,
		height,
		NULL,
		NULL,
		wc.hInstance,
		NULL
	);

	if (!this->windowHandle)
	{
		printf("No window handle!");
		return;
	}

	ShowWindow(this->windowHandle, SW_SHOW);
	UpdateWindow(this->windowHandle);
}

Window::~Window()
{
	UnregisterClassA(this->className, GetModuleHandle(NULL));
}

bool Window::PumpMessages()
{
	MSG msg;

	if (PeekMessageA(&msg, this->windowHandle, NULL, NULL, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		return true;
	}
	else
	{
		return false;
	}
}