#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "Application.h"
#include "Window.h"

#define SAFE_DELETE(x) { if (x) { delete x; x = nullptr; } }

void Application::Initialize()
{
	this->win = new Window("Test");
}

void Application::Run()
{
	while (!this->bShutdown)
	{
		this->win->PumpMessages();
	}
}

void Application::Shutdown()
{
	SAFE_DELETE(this->win);
}
