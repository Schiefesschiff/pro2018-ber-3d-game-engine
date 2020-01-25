#pragma once

//===== ===== Extern ===== =====
//===== ===== Intern ===== =====

#define MAX_COMPONENTS 16

class Entity;


class Component {
	friend Entity;

public:
	virtual void OnCreate(void) {};
	virtual void OnUpdate(float deltaTime) {};
	virtual void OnDestroy(void) {};

	static const int TypeID = -1;

protected:

	Entity* GetDad(void) { return dad; };

private:
	Entity* dad;
};
