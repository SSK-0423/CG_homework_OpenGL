#include "HindLegAnimator.h"
#include "Lerp.h"

HindLegAnimator::HindLegAnimator()
{
	state = 0;
	type = 0;
	int step = 400;
	MakeLerpList(legRotateList, legLerp, step);
	MakeLerpList(firstJoint, firstJointLerp, step);
	MakeLerpList(secondJoint, secondJointLerp, step);
}

void HindLegAnimator::Animation(double& legRotateY, double& legRotateZ, double& firstJointRotate, double& secondJointRotate, float& speed)
{
	if (type == 0) {
		legRotateZ = legLerp[state % legLerp.size()];
		firstJointRotate = firstJointLerp[state % firstJointLerp.size()];
		secondJointRotate = secondJointLerp[state % secondJointLerp.size()];
	}
	else if (type == 1 && state >= legLerp.size() / 2) {
		legRotateZ = legLerp[(state - legLerp.size() / 2) % legLerp.size()];
		firstJointRotate = firstJointLerp[(state - firstJointLerp.size() / 2) % firstJointLerp.size()];
		secondJointRotate = secondJointLerp[(state - secondJointLerp.size() / 2) % secondJointLerp.size()];
	}
	state += 1;
}

void HindLegAnimator::ChangeAnimeType(int type)
{
	this->type = type;
}
