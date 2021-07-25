#pragma once
#include "GameData.h"

enum CAMERATYPE {
	CAMERA_TPS,
	CAMERA_FPS
};

class Camera {
private:
	// カメラ座標
	Position3D<float> position;
	Position3D<float> viewPosition;
	int cameraType;
	int angle;
public:
	Camera();
	// 描画
	void Draw();
	// カメラの移動
	void MovePosition(float x, float y, float z);
	void SetPosition(float x, float y, float z);
	void SetPosition(Position3D<float> pos);
	void SetViewPosition(float x, float y, float z);
	void SetViewPosition(Position3D<float> pos);
	// カメラの回転
	void Rotate(int angle);
	// カメラ変更
	void ChangeCamera(int num);
};