#pragma once

//===== ===== Extern ===== =====
//===== ===== Intern ===== =====

#define INVALID_COMPONENT_ID -1;

class Entity;

static int ComponentCount = 0;//0 is Reserved for Transform

class Component {
	friend Entity;

public:
	template <typename T>
	void RegisterComponentType() {
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
	static const int TypeID = INVALID_COMPONENT_ID;
	Entity* dad;
};
