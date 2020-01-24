#pragma once

//===== ===== Extern ===== =====
#include <vector>

//===== ===== Intern ===== =====
#include "Scene.h"
#include "Singleton.h"

class Entity;

class GameInstance final {
	GE_DECLARE_SINGLETON(GameInstance);

public:
	/*!
	 * @brief unload old scene, change currentScene to newScene, load new scene
	 */
	void ChangeScene(int newScene);

	/*!
	 * @brief adds the virtualEntity to the virtualEntities array
	 */
	void Add(Entity* virtualEntity);

	/*!
	 * @brief removes the virtualEntity to the virtualEntities array
	 */
	void Remove(Entity* virtualEntity);

	/*!
	 * @brief			updates the current scene and all virtual Entities
	 * @param deltaTime	the time between last frame and current frame in seconds
	 */
	void UpdateCurrentScene(float deltaTime);

private:

	std::vector<Scene> scenes;
	int currentScene;

	std::vector<Entity*> virtualEntities;
};