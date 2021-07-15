#pragma once
#include "Texture.h"
#include "Component.hpp"

class Floor : public Component {
private:
	static Texture* texture;
public:
	Floor();
	~Floor();
	void Update();
	void Draw();
};