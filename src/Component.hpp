#pragma once
#include "Object.hpp"
class Object;

class Component {
protected:
	// �R���|�[�l���g���g�����I�u�W�F�N�g
	Object* parent;

public:
	Component() {
		parent = nullptr;
	}
	virtual ~Component() {
	}
	virtual void Update() {};
	virtual void Draw() {};

	virtual void SetParentObject(Object& obj) {
		parent = &obj;
	}
};