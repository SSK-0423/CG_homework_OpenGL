#include "MiddleLegAnimator.h"
#include "GL/glut.h"
#include "Lerp.h"
MiddleLegAnimator::MiddleLegAnimator()
{
	type = 0;
	state = 0;
	int step = 1000;
	MakeLerpList(legRotateZList, legZLerp, step);
	MakeLerpList(legRotateYList, legYLerp, step);
}

void MiddleLegAnimator::Animation(double& legRotateY, double& legRotateZ, double& firstJointRotate, double& secondJointRotate, float& speed)
{
	if (type == 0) {
		//legRotateZ = legZLerp[state % legZLerp.size()];
		legRotateY = legYLerp[state % legYLerp.size()];
	}
	else if (type == 1) {

	}
	state += 1;
}

void MiddleLegAnimator::ChangeAnimeType(int type)
{
	this->type = type;
}


