#pragma once

//===== ===== Extern ===== =====
//===== ===== Intern ===== =====
#include "Entity.h"

class Scene final {
public:
	/*!
	 * @brief	initialice all entitys and component in scene (fake would be loaded from file).
	 *			call Create() funktion of root element.
	 */
	void Load();

	/*!
	 * @brief start Update() call in root entity
	 */
	void Update(float deltaTime);

	/*!
	 * @brief	call Destroy() funktion of root element.
	 */
	void Unload();

	/*!
	 * @brief	saves newCamera to mainCamera
	 */
	void SetMainCamera(Entity* newCamera);

private:
	Entity* root;

	Entity* mainCamera;
};