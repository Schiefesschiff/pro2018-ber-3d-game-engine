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

	static u64 ActiveEntities;

public:

	Entity(bool hasTransform = true);

	/*!
	 * @brief adds component to component list if it dosnt already exist
	 */
	void AddComponent(Component* component);

	/*!
	 * @brief removes component to component list if it dosnt already exist
	 */
	void RemoveComponent(Component* component);

	/*!
	 * @brief sets this.perant to parent and disataches from old and ataches to new parents children
	 */
	bool AttachTo(Entity* parent);

	/*!
	 * @brief sets this.perant to null and disataches from old parents children
	 */
	void Detatch(void);

	/*!
	 * @brief sets this.perant to null and disataches from old parents children
	 */
	Entity* FindChildEntity(Entity* parent);

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
	 * @brief calls all updates in cildren and components
	 */
	void Update(float deltaTime);

	/*!
	 * @brief calls all destroy in cildren and components
	 */
	void Destroy(void);

private:

	u64 entityID = 0;
	Entity* parent = nullptr;
	std::list<Entity*> children;
	std::list<Component*> components;
	bool isVirtual;
};