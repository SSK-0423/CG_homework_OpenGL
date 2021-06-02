#pragma once
#include "Vector3D.h"
class Camera {
private:
	// カメラ座標
	Vector3D position;
	Vector3D viewPosition;
	int cameraType;
	int angle;
public:
	Camera();
	// 描画
	void Draw();
	// カメラの移動
	void MovePosition(float x, float y, float z);
	void SetPosition(float x, float y, float z);
	void SetViewPosition(float x, float y, float z);
	// カメラの回転
	void Rotate(int angle);
	// カメラ変更
	void ChangeCamera(int num);
};