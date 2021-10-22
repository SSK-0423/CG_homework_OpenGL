#pragma once
#include "Animator.h"
class LegAnimator : public Animator<double&, double&, double&, double&, float&> {
public:
	virtual void Animation(double& legRotateY, double& legRotateZ, double& firstJointRotate, double& secondJointRotate, float& speed) = 0;
};