#pragma once
#include "Vector3D.h"
class Camera {
private:
	// カメラ座標
	Vector3D position;
	int cameraType;
public:
	Camera();
	// 描画
	void Draw();
	// カメラの移動
	void MovePosition(float x, float y, float z);
	void SetPosition(float x, float y, float z);
	void SetViewPosition(float x, float y, float z);
	// カメラの回転
	//void Rotate();
	// カメラ変更
	void ChangeCamera(int num);
};