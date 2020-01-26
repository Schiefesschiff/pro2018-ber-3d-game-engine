#include "GameInstance.h"

#include <cassert>

#include "Entity.h"
#include "Window.h"

GE_DEFINE_SINGLETON(GameInstance)

void GameInstance::InitGame(void) {
	scenes.push_back(Scene());
	currentScene = 0;
	scenes[currentScene].Load();
}


void GameInstance::ChangeScene(int newScene)
{
	if(newScene < 0 || newScene >= scenes.size())
		return;

	scenes[currentScene].Unload();
	currentScene = newScene;
	scenes[currentScene].Load();
}

void GameInstance::Add(Entity& virtualEntity)
{
	virtualEntities.push_back(&virtualEntity);
}

void GameInstance::Remove(Entity& virtualEntity)
{
}

void GameInstance::UpdateCurrentScene(float deltaTime)
{
	for(auto& it : virtualEntities)
		it->Update(deltaTime);

	scenes[currentScene].Update(deltaTime);
}

void GameInstance::RenderCurrentScene(Window& target) {
	assert(false && "not implimented");
}

void GameInstance::Shutdown(void) {
	scenes[currentScene].Unload();

	scenes.clear();
}
