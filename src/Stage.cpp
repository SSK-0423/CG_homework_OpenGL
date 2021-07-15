#include "Stage.h"
#include "GL/glut.h"
#include "GameData.h"
#include "Transform.hpp"

void Stage::MakeStage()
{
	for (int i = -MAP_HEIGHT / 2; i < MAP_HEIGHT / 2; i++) {
		for (int j = -MAP_WIDTH / 2; j < MAP_WIDTH / 2; j++) {
			//床オブジェクト追加
			if (map[i + 4][j + 4] == 0) {
				GameObject* obj = new GameObject();
				obj->AddComponent<Floor>();
				obj->GetComponent<Transform>()->SetPosition(10 * j, -1, 10 * i);
				obj->GetComponent<Transform>()->SetSize(10, 1, 10);
				stageObjList.push_back(obj);
			}

			//ビルオブジェクト追加
			if (map[i + 4][j + 4] == 1) {
				GameObject* obj = new GameObject();
				obj->AddComponent<Building>();
				obj->GetComponent<Transform>()->SetPosition(10 * j, 7.5, 10 * i);
				obj->GetComponent<Transform>()->SetSize(5, 15, 5);
				stageObjList.push_back(obj);
			}
		}
	}
}

Stage::Stage()
{
	skybox = new GameObject();
	skybox->AddComponent<SkyBox>();
	MakeStage();
}

Stage::~Stage() {
	for (auto obj : stageObjList) {
		delete obj;
	}
	stageObjList.clear();
}

void Stage::Draw() {
	//skybox->Draw();
	for (auto obj : stageObjList) {
		obj->Draw();
	}
}