#include "Scene.h"

void Scene::Load()
{
}

void Scene::Update(float deltaTime)
{
	root->Update(deltaTime);
}

void Scene::Unload()
{
	root->Destroy();
	delete(root);
	root = nullptr;
}

void Scene::SetMainCamera(Entity * newCamera)
{
	this->mainCamera = newCamera;
}
