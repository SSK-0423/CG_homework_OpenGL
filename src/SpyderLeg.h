#pragma once
#include "BodyPart.h"
#include "Animator.h"
class SpyderLeg : public BodyPart<float,float,float,int> {
private:
	// アニメーター
	Animator<double&,double&,float&>* animator;
	// 脚の上下角度
	double legRotateZ;
	// 脚の前後角度
	double legRotateY;
	// アニメーションスピード
	float speed;
public:
	SpyderLeg();
	void Draw(float x, float y, float z,int num);
	void Animation();
	void SetPosition(float x, float y, float z);
	void SetAnimator(Animator<double&,double&,float&>& animator);
};