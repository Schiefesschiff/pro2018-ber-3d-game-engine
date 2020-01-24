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

	Entity(std::list<Component*> startComponents);

	/*!
	 * @brief adds component to component list if it doesnt already exist
	 */
	void AddComponent(Component* component);

	/*!
	 * @brief removes component to component list if it doesnt already exist
	 */
	void RemoveComponent(Component* component);

	/*!
	 * @brief sets this.parent to parent and detaches from old and attaches to new parents children
	 */
	bool AttachTo(Entity* parent);

	/*!
	 * @brief sets this.parent to null and detaches from old parents children
	 */
	void Detatch(void);

	/*!
	 * @brief sets this.parent to null and detaches from old parents children
	 */
	//Entity* FindChildEntity(Entity* parent);

	/*!
	 * @return chlidens list
	 */
	const std::list<Entity*>& GetChildren(void);

	std::string name;

protected:

	/*!
	 * @brief calls all creates in components
	 */
	void Create(void);

	/*!
	 * @brief calls all updates in children and components
	 */
	void Update(float deltaTime);

	/*!
	 * @brief calls all destroy in children and components
	 */
	void Destroy(void);

private:

	u64 entityID = 0;
	Entity* parent = nullptr;
	std::list<Entity*> children;
	std::list<Component*> components;
};
