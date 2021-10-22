#pragma once
#include "BodyPart.h"
#include "Animator.h"
#include "Material.h"
#include <vector>
class SpyderLeg : public BodyPart<float, float, float, int> {
private:
	float mtr[2][4] = {
		{0.5,0.25,0.0,0.0},
		{0.5,0.4,0.0,0.0},
	};
	Material material;
	MaterialParam param = {
		{0.1,0.1,0.1,1.0},
		{0.53,0.29,0.17,1.0},
		{0.0,0.0,0.0,1.0},
		{0.0,0.0,0.0,1.0},
		0
	};
	Material material2;
	MaterialParam param2 = {
		{0.1,0.1,0.1,1.0},
		{0.3,0.2,0.1,1.0},
		{0.0,0.0,0.0,1.0},
		{0.0,0.0,0.0,1.0},
		0
	};
	// アニメーター
	Animator<double&, double&, double&, double&, float&>* animator;
	// 脚の上下角度
	double legRotateZ;
	// 脚の前後角度
	double legRotateY;
	// 第一関節の角度
	double firstJointRotate;
	// 第二関節の角度
	double secondJointRotate;
	// アニメーションスピード
	float speed;
public:
	SpyderLeg();
	void Draw(float x, float y, float z, int num);
	void Animation();
	void SetPosition(float x, float y, float z);
	void SetAnimator(Animator<double&, double&, double&, double&, float&>& animator);
};