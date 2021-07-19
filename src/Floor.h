#pragma once
#include "Component.hpp"
#include "Transform.hpp"
#include "Texture.h"

class Floor : public Component {
private:
	static Texture* texture;
	Transform* parentTransform;
public:
	Floor(const char* filepath);
	~Floor();
	void Update();
	void Draw();
};