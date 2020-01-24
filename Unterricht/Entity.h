#pragma once

//===== ===== Extern ===== =====
#include <list>
#include <string>

//===== ===== Intern ===== =====
#include "Types.h"

class Component;

class Entity final
{
	friend class Scene;

public:

	Entity();

	void AddComponent(Component* component);
	bool AttachTo(Entity* parent);
	void Detatch(void);
	Entity* FindChildEntity(Entity* parent);
	const std::list<Entity*>& GetChildren(void);

	std::string name;

protected:
	void Create(void);
	void Update(real deltaTime);
	void Destroy(void);

private:

	static u64 ActiveEntities;

	u64 entityID = 0;
	Entity* parent = nullptr;
	std::list<Entity*> children;
	std::list<Component*> components;
};