#pragma once
#include "Vector3D.h"

class Ant {
private:
	double legRotateZ;
	double legRotateY;
	float speed;
	//座標
	Vector3D position;
	// 頭
	void DrawHead(float x, float y, float z);
	// 胴体
	void DrawBody(float x, float y, float z);
	// 足
	void DrawLeg(float x, float y, float z, int num);
	// しっぽ
	void DrawTale(float x, float y, float z);
	// 目
	void DrawEye(float x, float y, float z, double sx, int slices, int stacks);
	// 触覚
	void DrawTactile(float x, float y, float z);
	// 糸
	void DrawThread(float x, float y, float z,int angle);
public:
	Ant();
	//描画関数
	void Draw();
	// 移動
	void MovePosition(float x, float y, float z);
	// アニメーション
	void Animation();
};