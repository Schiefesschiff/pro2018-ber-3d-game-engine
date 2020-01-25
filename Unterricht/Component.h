#pragma once

//===== ===== Extern ===== =====
//===== ===== Intern ===== =====

class Entity;

class Component {
	friend Entity;
	friend Transform;

public:
	virtual void OnCreate(void) {};
	virtual void OnUpdate(float deltaTime) {};
	virtual void OnDestroy(void) {};

protected:

	Entity* GetDad(void) { return dad; };

private:
	Entity* dad;
	virtual bool isTransform() { return false; };
};
