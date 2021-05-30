#pragma once
#include "Animator.h"

class FrontLegAnimator : public Animator<double&,double&,float&>{
public:
	void Animation(double& legRotateY, double& legRotateZ, float& speed);
};