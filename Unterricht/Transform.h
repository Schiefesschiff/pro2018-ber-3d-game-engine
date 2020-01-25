#pragma once

//===== ===== Extern ===== =====
//===== ===== Intern ===== =====
#include "Component.h"

class Transform : public Component {

private:
	bool isTransform() override final { return true; };
};
