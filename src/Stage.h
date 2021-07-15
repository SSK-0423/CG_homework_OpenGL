#pragma once
#include "Building.h"
#include "Floor.h"
#include "SkyBox.h"
#include "GameObject.hpp"
#include <vector>
#define MAP_WIDTH 8
#define MAP_HEIGHT 8

class Stage {
private:
	GameObject* skybox;
	std::vector<GameObject*> stageObjList;
	float map[MAP_WIDTH][MAP_HEIGHT] = {
		{1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1}
	};

	void MakeStage();
public:
	Stage();
	~Stage();
	void Draw();
};