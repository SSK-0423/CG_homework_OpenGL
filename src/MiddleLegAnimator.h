#pragma once
#include "Animator.h"
#include <vector>
class MiddleLegAnimator : public Animator<double&, double&, double&, double&, float&> {
private:
	int type;
	int state;
	std::vector<int> legRotateZList = { 30,45,45,30,30 };
	std::vector<float> legZLerp;
	std::vector<int> legRotateYList = { 0,0,30,30,0 };
	std::vector<float> legYLerp;
	std::vector<int> firstJoint = { 90,90,30,90 };
	std::vector<float> firstJointLerp;
public:
	MiddleLegAnimator();
	void Animation(double& legRotateY, double& legRotateZ, double& firstJointRotate, double& secondJointRotate, float& speed);
	void ChangeAnimeType(int type);
};