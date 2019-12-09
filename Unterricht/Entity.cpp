#include "Entity.h"

u64 Entity::ActiveEntities = 0;

Entity::Entity() : entityID(++ActiveEntities)
{

}

void Entity::AddComponent(BaseComponent* component)
{
	this->components.push_back(component);
}

bool Entity::AttachTo(Entity* parent)
{
	if (!parent)
		return false;

	if (this->entityID != parent->entityID && !this->FindChildEntity(parent))
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

Entity* Entity::FindChildEntity(Entity* parent)
{
	for (auto& child : this->children)
	{
		if (child != nullptr)
		{
			if (parent->entityID == child->entityID)
				return child;

			if (auto ret = child->FindChildEntity(parent))
				return ret;
		}
	}

	return nullptr;
}

void Entity::Update(real deltaTime)
{
	printf("Update %s in %f\n", this->name.c_str(), deltaTime);
}

const std::list<Entity*>& Entity::GetChildren()
{
	return this->children;
}