#pragma once
#include "Component.hpp"
#include "Texture.h"

class SkyBox : public Component {
private:
	Texture* texture;

public:
	SkyBox();
	~SkyBox();
	void Update();
	void Draw();
};