#pragma once

#include <list>

#include "Types.h"

class BaseComponent;

class Entity
{

public:

	Entity();

	void AddComponent(BaseComponent* component);
	bool AttachTo(Entity* parent);
	void Detatch(void);
	Entity* FindChildEntity(Entity* parent);
	const std::list<Entity*>& GetChildren();

	virtual void Update(real deltaTime);

	std::string name;


private:

	static u64 ActiveEntities;

	u64 entityID = 0;
	Entity* parent = nullptr;
	std::list<Entity*> children;
	std::list<BaseComponent*> components;
};