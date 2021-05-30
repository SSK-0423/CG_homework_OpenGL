#include "FrontLegAnimator.h"
#include "GL/glut.h"
#include "Lerp.h"
#include "Debug.h"

FrontLegAnimator::FrontLegAnimator()
{
	state = 0;
	type = 0;
	int step = 1000;
	MakeLerpList(legRotateList, legLerp, step);
	MakeLerpList(firstJoint, firstJointLerp, step);
}

void FrontLegAnimator::Animation(double& legRotateY, double& legRotateZ, double& firstJointRotate, double& secondJointRotate, float& speed)
{
	char buff[64];
	sprintf_s(buff, "legRotateZ:%4.1lf", legRotateZ);
	DrawString(buff, -10, 0, -10);
	if (type == 0) {
		legRotateZ = legLerp[state % legLerp.size()];
		firstJointRotate = firstJointLerp[state % firstJointLerp.size()];
	}
	else if (type == 1 && state >= legLerp.size() / 2) {
		legRotateZ = legLerp[(state - legLerp.size() / 2) % legLerp.size()];
		firstJointRotate = firstJointLerp[(state - firstJointLerp.size() / 2) % firstJointLerp.size()];
	}
	state += 1;
}

void FrontLegAnimator::ChangeAnimeType(int type)
{
	this->type = type;
}

//sprintf_s(buff, "fabs:%4.1f", fabs(legRotateZ - legRotateList[(state+1) % 3]));
//DrawString(buff, -10, 0, -8);
//sprintf_s(buff, "RotateList:%d", legRotateList[state % 3]);
//DrawString(buff, -10, 0, -6);