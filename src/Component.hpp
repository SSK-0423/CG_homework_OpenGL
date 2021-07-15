#pragma once
#include "Object.hpp"
class Object;

class Component {
protected:
	// コンポーネント自身を持つオブジェクト
	Object* parent;

public:
	Component() {
		parent = nullptr;
	}
	virtual ~Component() {
	}
	virtual void Update() = 0;
	virtual void Draw() = 0;

	void SetParentObject(Object& obj) {
		parent = &obj;
	}
};