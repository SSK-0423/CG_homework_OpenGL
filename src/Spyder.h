#pragma once
#include "Vector3D.h"
#include "SpyderHead.h"
#include "SpyderLeg.h"
#include "SpyderTale.h"
#include "FrontLegAnimator.h"
#include "MiddleLegAnimator.h"

class Spyder {
private:
	//�O�r�̃A�j���[�^
	static FrontLegAnimator frontLegAni;
	//��r�̃A�j���[�^
	static MiddleLegAnimator middleLegAni;
	//���W
	Vector3D position;
	//6�{�r
	SpyderLeg leg[8];
	//��
	SpyderHead head;
	//��
	SpyderTale tale;
	// �A�j���[�V�����̐ݒ�
	void InitAnimation();
public:
	Spyder();
	//�`��֐�
	void Draw();
	// �ړ�
	void MovePosition(float x, float y, float z);
	// �A�j���[�V����
	void Animation();
};