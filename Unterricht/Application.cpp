#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <functional>

#include "Application.h"
#include "Window.h"
#include "Utils.h"
#include "Clock.h"
#include "Entity.h"

GE_DEFINE_SINGLETON(Application);

void Application::Initialize()
{
	this->meAppState = ApplicationState::Started;

	Clock::GetInstance().Initialize();

	this->win = new Window();
	this->win->Initialize("Game Engine Test");
}

void Application::Run(void)
{
	Entity world;
	Entity box;

	world.name = "World";
	box.name = "Box";

	if (!box.AttachTo(&world))
		printf("Failed to attach box to world!");

	this->meAppState = ApplicationState::Running;

	while (this->meAppState == ApplicationState::Running)
	{
		if (!this->win->PumpMessages())
			this->meAppState = ApplicationState::Stopped;

		auto elapsedTime = static_cast<real>(Clock::GetInstance().GetElapsedTime()) / 1000.0f;
	
		// Update Game
		world.Update(elapsedTime);


		std::function<void(Entity*)> sceneUpdate = [&sceneUpdate, &elapsedTime](Entity* entity)
		{
			for (auto& child : entity->GetChildren())
			{
				child->Update(elapsedTime);
				sceneUpdate(entity);
			}
		};

		// Render Frame

		Sleep(100);
		//printf("Elapsed time: %lld ms\n", Clock::GetInstance().GetElapsedTime());
	}
}

void Application::Shutdown()
{
	SAFE_DELETE(this->win);
}
