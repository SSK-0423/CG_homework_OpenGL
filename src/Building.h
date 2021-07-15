#pragma once
#include "Component.hpp"
#include "Texture.h"
#include "GameData.h"

class Building : public Component{
private:
	static Texture* texture;
public:
	Building();
	~Building();
	void Update();
	void Draw();
};