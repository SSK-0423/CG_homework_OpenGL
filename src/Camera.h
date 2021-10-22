#pragma once
#include "GameData.h"

enum CAMERATYPE {
	CAMERA_TPS,
	CAMERA_FPS
};

class Camera {
private:
	// �J�������W
	Position3D<float> position;
	Position3D<float> viewPosition;
	int cameraType;
	int angle;
public:
	Camera();
	// �`��
	void Draw();
	// �J�����̈ړ�
	void MovePosition(float x, float y, float z);
	void SetPosition(float x, float y, float z);
	void SetPosition(Position3D<float> pos);
	void SetViewPosition(float x, float y, float z);
	void SetViewPosition(Position3D<float> pos);
	// �J�����̉�]
	void Rotate(int angle);
	// �J�����ύX
	void ChangeCamera(int num);
};