#pragma once
#include "BodyPart.h"
#include "Animator.h"
#include "PlayerLegAnimator.h"
class PlayerLeg : public BodyPart<const float&, const float&, const float&, bool,int>
{
private:
	// �A�j���[�^�[
	Animator<double&, double&, double&, double&, bool>* animator;
	// X����]
	double legRotateX;
	// �Ҋ֐߂̊p�x
	double firstJointRotate;
	// �G�̊p�x
	double secondJointRotate;
	// ����̊p�x
	double thirdJointRotate;
public:
	PlayerLeg();
	~PlayerLeg();
	void Draw(const float& x, const float& y, const float& z,bool inv,int state);
	void Animation();
	void Animation(bool inverse);
	void SetPosition(float x, float y, float z);
	void AddAngle(float value, int num);
};