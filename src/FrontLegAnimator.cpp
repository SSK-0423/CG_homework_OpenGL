#include "FrontLegAnimator.h"

void FrontLegAnimator::Animation(double& legRotateY, double& legRotateZ, float& speed)
{
	if (legRotateZ < 90) {
		legRotateZ += speed;
	}
	else if (legRotateZ >= 90 && legRotateY < 90) {
		legRotateZ = 90;
		legRotateY += speed;
	}
	else if (legRotateY >= 90 && legRotateZ < 180) {
		legRotateY = 90;
		legRotateZ += speed;
	}
	else if (legRotateZ >= 180 && legRotateY < 180) {
		legRotateZ = 180;
		legRotateY += speed;
	}
	else {
		legRotateY = 0;
		legRotateZ = 0;
	}
}
