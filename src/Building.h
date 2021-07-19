#pragma once
#include "Component.hpp"
#include "Texture.h"
#include "GameData.h"
#include "Transform.hpp"
#include <vector>

class Building : public Component{
private:
	Texture* texture;
	Transform* parentTransform;
public:
	Building(const char* filepath);
	~Building();
	void Update();
	void Draw();
};