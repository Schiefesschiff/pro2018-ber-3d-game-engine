#include "Entity.h"
#include <algorithm>

#include "Component.h"
#include "Transform.h"
#include "GameInstance.h"

u64 Entity::ActiveEntities = 0;

Entity::Entity(Entity* parent/* = nullptr*/) : entityID(++ActiveEntities)
{
	isVirtual = nullptr == parent;

	components.resize(MAX_COMPONENTS);

	if(isVirtual) {
		AddComponent<Transform>();
		AttachTo(parent);
	} else {
		GameInstance::GetInstance().Add(this);
	}
}

bool Entity::AttachTo(Entity* parent)
{
	if (!parent || isVirtual)
		return false;

	if(this->entityID != parent->entityID) //&& check if parent is a child of this entity
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

Entity* Entity::FindChildEntity(Entity* parent) {
	for(auto& child : this->children) {
		if(child != nullptr) {
			if(parent->entityID == child->entityID)
				return child;

			if(auto ret = child->FindChildEntity(parent))
				return ret;
		}
	}

}

const std::list<Entity*>& Entity::GetChildren()
{
	return this->children;
}

void Entity::Create(void) {
	for(auto& it : components)
		it->OnCreate();
}

void Entity::Update(float deltaTime) {
	for(auto& it : components)
		it->OnUpdate(deltaTime);

	for(auto& it : children)
		it->Update(deltaTime);
}

void Entity::Destroy(void) {
	Detatch();

	for(auto& it : components)
		it->OnDestroy();
	this->components.clear();

	for(auto& it : children)
		it->Destroy();
	this->children.clear();
}
