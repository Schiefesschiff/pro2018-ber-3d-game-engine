#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <functional>

#include "Application.h"
#include "Window.h"
#include "Utils.h"
#include "Clock.h"
#include "Entity.h"
#include "GameInstance.h"

GE_DEFINE_SINGLETON(Application);

void Application::Initialize()
{
	this->meAppState = ApplicationState::Started;

	Clock::GetInstance().Initialize();

	this->win = new Window();
	this->win->Initialize("Game Engine Test");

	game = GameInstance::GetInstancePtr();
	game->InitGame();
}

void Application::Run(void)
{
	this->meAppState = ApplicationState::Running;

	while (this->meAppState == ApplicationState::Running)
	{
		if (!this->win->PumpMessages())
			this->meAppState = ApplicationState::Stopped;

		auto elapsedTime = static_cast<real>(Clock::GetInstance().GetElapsedTime()) / 1000.0f;
	
		// Update Game
		game->UpdateCurrentScene(elapsedTime);

		// Render Frame
		game->RenderCurrentScene(*win);
	}
}

void Application::Shutdown()
{
	game->Shutdown();
	SAFE_DELETE(this->win);
}
