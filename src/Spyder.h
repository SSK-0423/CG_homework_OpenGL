#pragma once
#include "Vector3D.h"
#include "SpyderBody.h"
#include "SpyderHead.h"
#include "SpyderLeg.h"
#include "SpyderTale.h"

class Spyder {
private:
	double legRotateZ;
	double legRotateY;
	float speed;
	//���W
	Vector3D position;
	// ��
	void DrawHead(float x, float y, float z);
	// ����
	void DrawBody(float x, float y, float z);
	// ��
	void DrawLeg(float x, float y, float z, int num);
	// ������
	void DrawTale(float x, float y, float z);
	// ��
	void DrawEye(float x, float y, float z, double sx, int slices, int stacks);
	// �G�o
	void DrawTactile(float x, float y, float z);
	// ��
	void DrawThread(float x, float y, float z,int angle);
public:
	Spyder();
	//�`��֐�
	void Draw();
	// �ړ�
	void MovePosition(float x, float y, float z);
	// �A�j���[�V����
	void Animation();
};