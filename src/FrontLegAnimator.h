#pragma once
#include "Animator.h"
#include <vector>

class FrontLegAnimator : public Animator<double&, double&, double&, double&, float&> {
private:
	int state;
	int type;
	std::vector<int> legRotateList = { 30,60,0,30 };
	std::vector<float> legLerp;
	std::vector<int> firstJoint= { 90,90,0,90 };
	std::vector<float> firstJointLerp;
	std::vector<int> secondJoint = { 30,30,15,30 };
	std::vector<float> secondJointLerp;


public:
	FrontLegAnimator();
	void Animation(double& legRotateY, double& legRotateZ, double& firstJointRotate, double& secondJointRotate,float& speed);
	void ChangeAnimeType(int type);
};