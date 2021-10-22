#pragma once
#include "Component.hpp"
#include "Texture.h"
#include "GameData.h"
#include "Transform.hpp"
#include "Material.h"
#include <vector>

class Building : public Component{
private:
	Texture* texture;
	Transform* parentTransform;
	Material* material;
	MaterialParam param = {
		{0.8,0.8,0.8,1.0},
		{1.0,1.0,1.0,1.0},
		{0.2,0.2,0.2,1.0},
		{0,0,0,1.0},
		0
	};
	float vec[8][3] = {
		{0,1,0},
		{1,0,0},
		{0,1,0},
		{1,0,0},
		{0,1,0},
		{0,0,1},
		{0,0,1},
		{0,-1,0}
	};
public:
	Building(const char* filepath);
	~Building();
	void Update();
	void Draw();
};