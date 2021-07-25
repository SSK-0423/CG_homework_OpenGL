#pragma once
#include "Building.h"
#include "Floor.h"
#include "GameObject.hpp"
#include <vector>
#include <string.h>
#define MAP_WIDTH 16
#define MAP_HEIGHT 16

class Stage {
private:
	GameObject skybox;
	GameObject floor;
	std::vector<GameObject*> stageObjList;
	std::vector<GameObject*> floorObjList;
	std::vector<GameObject*> buildingObjList;
	std::vector<std::string> filepaths;
	float map[MAP_HEIGHT][MAP_WIDTH] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1},
		{1,0,0,1,1,1,1,0,0,0,0,0,1,0,0,1},
		{1,0,0,1,1,1,1,0,0,1,0,0,1,0,0,1},
		{1,0,0,1,1,1,1,0,0,1,0,0,1,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1},
		{1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1},
		{1,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1},
		{1,0,0,1,0,1,0,0,0,1,0,0,1,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	void MakeStage();
public:
	Stage();
	~Stage();
	void Draw();
};