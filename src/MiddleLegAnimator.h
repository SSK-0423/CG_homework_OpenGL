#pragma once
#include "Animator.h"
class MiddleLegAnimator : public Animator<double, double, float> {
public:
	void Animation(double legRotateY, double legRotateZ, float speed);
};