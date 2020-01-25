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

	Entity(Entity* parent = nullptr);

	/*!
	 * @brief adds component to component list if it dosnt already exist
	 */
	template<typename T>
	void AddComponent(void) {
		if(isVirtual && T::TypeID <= 0)//0 is Transform
			return;

		components[T::TypeID] = new T;
		components[T::TypeID].OnCreate();
	}

	/*!
	 * @brief removes component to component list if it dosnt already exist
	 */
	template<typename T>
	void RemoveComponent(void) {
		if(!HasComponents<T> || T::TypeID <= 0)//0 is Transform. Transform cand be Removed
			return;

		this->components[T::TypeID].OnDestroy();
		this->components[T::TypeID] = nullptr;
	}

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

	template <typename T>
	T* GetComponent(void) {
		return reinterpret_cast<T*>(this->components[T::TypeID]);
	}

	template<typename T>
	bool HasComponents(void) {
		return this->components[T::TypeID] != nullptr;
	}

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
