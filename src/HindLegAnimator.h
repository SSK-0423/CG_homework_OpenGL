#pragma once
#include "Animator.h"
#include <vector>
class HindLegAnimator : public Animator<double&, double&, double&, double&, float&> {
private:
	int state;
	int type;
	std::vector<int> legRotateList = { 30,0,45,30 };
	std::vector<float> legLerp;
	std::vector<int> firstJoint = { 90,15,60,90 };
	std::vector<float> firstJointLerp;
	std::vector<int> secondJoint = { 30,0,15,30 };
	std::vector<float> secondJointLerp;
public:
	HindLegAnimator();
	void Animation(double& legRotateY, double& legRotateZ, double& firstJointRotate, double& secondJointRotate, float& speed);
	void ChangeAnimeType(int type);
};