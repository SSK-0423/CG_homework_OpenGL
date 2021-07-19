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
	virtual void Update() {};
	virtual void Draw() {};

	virtual void SetParentObject(Object& obj) {
		parent = &obj;
	}
};