#pragma once

//===== ===== Extern ===== =====
//===== ===== Intern ===== =====

class Entity;

class Component {
	friend Entity;

public:
	virtual void OnCreate(void) {};
	virtual void OnUpdate(float deltaTime) {};
	virtual void OnDestroy(void) {};

protected:

	Entity* GetDad(void) { return dad; };

private:
	Entity* dad;
};
