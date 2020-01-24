#pragma once

//===== ===== Extern ===== =====
//===== ===== Intern ===== =====

class Entity;

class Component {
	friend Entity;

public:
	void OnCreate(void) {};
	void OnUpdate(float deltaTime) {};
	void OnDestroy(void) {};

protected:

	Entity* GetDad(void);

private:
	Entity* dad;
};
