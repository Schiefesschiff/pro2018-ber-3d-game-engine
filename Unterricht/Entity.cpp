#include "Entity.h"
#include <algorithm>

u64 Entity::ActiveEntities = 0;

Entity::Entity(bool hasTransform/* = true*/) : entityID(++ActiveEntities)
{

}

void Entity::AddComponent(Component* component)
{
	this->components.push_back(component);
}

void Entity::RemoveComponent(Component* component)
{
	this->components.remove_if(component);
}

bool Entity::AttachTo(Entity* parent)
{
	if (!parent)
		return false;

	if (this->entityID != parent->entityID) //&& check if parent is a child of this entity
	{
		this->Detatch();
		this->parent = parent;
		this->parent->children.push_back(this);

		return true;
	}

	return false;
}

void Entity::Detatch(void)
{
	if (!this->parent)
		return;

	this->parent->children.remove(this);
	this->parent = nullptr;
}

const std::list<Entity*>& Entity::GetChildren(void)
{
	return this->children;
}

void Entity::Create(void)
{

}

void Entity::Update(real deltaTime)
{
	printf("Update %s in %f\n", this->name.c_str(), deltaTime);
}

void Entity::Destroy(void)
{
	
}
