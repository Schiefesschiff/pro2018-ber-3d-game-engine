#include "Entity.h"

#include "Component.h"

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

#ifdef NOT_IMPLIMENTED

Entity* Entity::FindChildEntity(Entity* parent) {
	for(auto& child : this->children) {
		if(child != nullptr) {
			if(parent->entityID == child->entityID)
				return child;

			if(auto ret = child->FindChildEntity(parent))
				return ret;
		}
	}

	return nullptr;
}

#endif // NOT_IMPLIMENTED

void Entity::Update(real deltaTime)
{
	printf("Update %s in %f\n", this->name.c_str(), deltaTime);
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