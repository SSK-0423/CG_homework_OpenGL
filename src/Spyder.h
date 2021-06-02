#pragma once
#include "Vector3D.h"
#include "SpyderHead.h"
#include "SpyderLeg.h"
#include "SpyderTale.h"
#include "FrontLegAnimator.h"
#include "MiddleLegAnimator.h"
#include "HindLegAnimator.h"
#include <vector>

class Spyder {
private:
	int angle;
	int state;
	//�O�r�̃A�j���[�^
	static FrontLegAnimator frontLegAni;
	//�����̋r�̃A�j���[�^
	static MiddleLegAnimator middleLegAni;
	//���r�̃A�j���[�^
	static HindLegAnimator hindLegAni;
	//6�{�r
	SpyderLeg leg[8];
	//��
	SpyderHead head;
	//��
	SpyderTale tale;
	//�ړ��p
	std::vector<int> z = { 0,-30, -30, 0,30,30,  30,  0, 0};
	std::vector<int> x = { 0,  0,  30,30,30, 0, -30,-30, 0};
	std::vector<float> xLerp;
	std::vector<float> zLerp;
	// �A�j���[�V�����̐ݒ�
	void InitAnimation();
	// �N���̈ړ��A�j���[�V����
	void MoveAnimation();
	void DebugDraw();
public:
	//���W
	Vector3D position;
	Spyder();
	//�`��֐�
	void Draw();
	// �ړ�
	void MovePosition(float x, float y, float z);
	// ��]
	void Rotate(int angle);
	// �A�j���[�V����
	void Animation();
	// �p�x�擾
	int GetAngle();
};