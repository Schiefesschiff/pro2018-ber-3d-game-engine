#pragma once

//===== ===== Extern ===== =====
//===== ===== Intern ===== =====
#include "Entity.h"

class Scene final {
public:
	void Update(float deltaTime);
	void Load();
	void Unload();

	void SetMainCamera(Entity& newCamera);

private:
	Entity root;

	Entity mainCamera;
};