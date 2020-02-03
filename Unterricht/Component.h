#pragma once

//===== ===== Extern ===== =====
//===== ===== Intern ===== =====

#define INVALID_COMPONENT_ID -1

class Entity;
class Transform;

static int ComponentCount = 0;//0 is Reserved for Transform

class Component {
	friend Entity;
	friend Transform;

public:
	template <typename T>
	static void RegisterComponentType(void) {
		ComponentCount++;

		if(T::TypeID == INVALID_COMPONENT_ID)
			T::TypeID = ComponentCount;
	}

	virtual void OnCreate(void) {};
	virtual void OnUpdate(float deltaTime) {};
	virtual void OnDestroy(void) {};


protected:

	Entity* GetDad(void) { return dad; };

private:
	static int TypeID;
	Entity* dad;
};
