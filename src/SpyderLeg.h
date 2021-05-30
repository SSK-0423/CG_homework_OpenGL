#pragma once
#include "BodyPart.h"
#include "Animator.h"
#include <vector>
class SpyderLeg : public BodyPart<float,float,float,int> {
private:
	// �A�j���[�^�[
	Animator<double&, double&, double&, double&, float&>* animator;
	// �r�̏㉺�p�x
	double legRotateZ;
	// �r�̑O��p�x
	double legRotateY;
	// ���֐߂̊p�x
	double firstJointRotate;
	// ���֐߂̊p�x
	double secondJointRotate;
	// �A�j���[�V�����X�s�[�h
	float speed;
public:
	SpyderLeg();
	void Draw(float x, float y, float z,int num);
	void Animation();
	void SetPosition(float x, float y, float z);
	void SetAnimator(Animator<double&, double&, double&, double&, float&>& animator);
};