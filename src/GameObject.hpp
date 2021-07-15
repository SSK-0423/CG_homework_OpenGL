#pragma once
#include "Object.hpp"
#include "Transform.hpp"

class GameObject : public Object {
protected:
	//À•W
	Transform transform;
public:
	GameObject() {
		componentList.push_back(&transform);
	}
	virtual ~GameObject() {
	}
	void Update() {
		for (auto comp : componentList) {
			comp->Update();
		}
	}
	void Draw() {
		for (auto comp : componentList) {
			comp->Draw();
		}
	}
};
