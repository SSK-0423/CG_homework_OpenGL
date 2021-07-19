#include "Stage.h"
#include "GL/glut.h"
#include "GameData.h"
#include "Transform.hpp"
#include "SkyBox.h"
#include <stdlib.h>
#include <stdio.h>

#define TILE_SIZE 15
void Stage::MakeStage()
{
	int index = 0;
	for (int i = -MAP_HEIGHT / 2; i < MAP_HEIGHT / 2; i++) {
		for (int j = -MAP_WIDTH / 2; j < MAP_WIDTH / 2; j++) {
			//ビルオブジェクト追加
			if (map[i + MAP_HEIGHT / 2][j + MAP_WIDTH / 2] == 1) {
				GameObject* obj = new GameObject();
				const char* path = filepaths[index % 3].c_str();
				obj->AddComponent<Building>(path);
				obj->GetComponent<Transform>()->SetPosition(TILE_SIZE * i, 0, TILE_SIZE * j);
				obj->GetComponent<Transform>()->SetSize(TILE_SIZE, TILE_SIZE * 2, TILE_SIZE);
				buildingObjList.push_back(obj);
			}
			index++;
		}
	}
}

Stage::Stage()
{
	skybox.AddComponent<SkyBox>();
	floor.AddComponent<Floor>("textures/asphalt.ppm");
	floor.GetComponent<Transform>()->SetSize(MAP_WIDTH * TILE_SIZE, 0.0, MAP_HEIGHT * TILE_SIZE);
	filepaths.push_back("textures/building.ppm");
	filepaths.push_back("textures/building2.ppm");
	filepaths.push_back("textures/building3.ppm");
	MakeStage();
}

Stage::~Stage() {
	for (auto obj : floorObjList) {
		delete obj;
	}
	for (auto obj : buildingObjList) {
		delete obj;
	}
	floorObjList.clear();
	buildingObjList.clear();
}

void Stage::Draw() {
	//skybox.Draw();
	floor.Draw();
	for (auto obj : buildingObjList) {
		obj->Draw();
	}
}