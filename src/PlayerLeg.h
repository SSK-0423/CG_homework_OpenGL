#pragma once
#include "BodyPart.h"
#include "Animator.h"
#include "PlayerLegAnimator.h"
class PlayerLeg : public BodyPart<const float&, const float&, const float&, bool,int>
{
private:
	// アニメーター
	Animator<double&, double&, double&, double&, bool>* animator;
	// X軸回転
	double legRotateX;
	// 股関節の角度
	double firstJointRotate;
	// 膝の角度
	double secondJointRotate;
	// 足首の角度
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