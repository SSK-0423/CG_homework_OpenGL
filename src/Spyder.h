#pragma once
#include "Vector3D.h"
#include "SpyderHead.h"
#include "SpyderLeg.h"
#include "SpyderTale.h"
#include "FrontLegAnimator.h"
#include "MiddleLegAnimator.h"
#include "HindLegAnimator.h"
#include "Texture.h"
#include "Material.h"
#include <vector>

class Spyder {
private:
	int angle;
	int state;
	//�O�r�̃A�j���[�^
	FrontLegAnimator frontLegAni;
	//�����̋r�̃A�j���[�^
	MiddleLegAnimator middleLegAni;
	//���r�̃A�j���[�^
	HindLegAnimator hindLegAni;
	//6�{�r
	SpyderLeg leg[8];
	//��
	SpyderHead head;
	//��
	SpyderTale tale;
	//�ړ��p
	std::vector<int> z = { 0,-90, -90, 0,90,90,  90,  0, 0 };
	std::vector<int> x = { 0,  0,  90,90,90, 0, -90,-90, 0 };
	std::vector<float> xLerp;
	std::vector<float> zLerp;

	float mtr[4] = { 0.5, 0.25, 0.0, 1.0 };
	Texture* bodyTexture;
	Material bodyMaterial;
	MaterialParam bodyParam = {
		{0.53,0.29,0.17,1.0},
		{0.53,0.29,0.17,1.0},
		{0.0,0.0,0.0,1.0},
		{0.0,0.0,0.0,1.0},
		0
	};
	int num;
	// �A�j���[�V�����̐ݒ�
	void InitAnimation();
	// �N���̈ړ��A�j���[�V����
	void MoveAnimation();
	// �f�o�b�O�p
	void DebugDraw();
public:
	//���W
	Vector3D position;
	Spyder(int num);
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