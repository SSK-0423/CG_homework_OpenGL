#pragma once
#include "Vector3D.h"
class Camera {
private:
	// �J�������W
	Vector3D position;
	Vector3D viewPosition;
	int cameraType;
	int angle;
public:
	Camera();
	// �`��
	void Draw();
	// �J�����̈ړ�
	void MovePosition(float x, float y, float z);
	void SetPosition(float x, float y, float z);
	void SetViewPosition(float x, float y, float z);
	// �J�����̉�]
	void Rotate(int angle);
	// �J�����ύX
	void ChangeCamera(int num);
};