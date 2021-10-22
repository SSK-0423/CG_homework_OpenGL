#include "MiddleLegAnimator.h"
#include "GL/glut.h"
#include "Lerp.h"
MiddleLegAnimator::MiddleLegAnimator()
{
	type = 0;
	state = 0;
	int step = 30;
	MakeLerpList(legRotateZList, legZLerp, step);
	MakeLerpList(legRotateYList, legYLerp, step);
}

void MiddleLegAnimator::Animation(double& legRotateY, double& legRotateZ, double& firstJointRotate, double& secondJointRotate, float& speed)
{
	//���O
	if (type == 0 && state >= legZLerp.size() / 8) {
		legRotateZ = legZLerp[(state - legZLerp.size() / 8) % legZLerp.size()];
		legRotateY = legYLerp[(state - legZLerp.size() / 8) % legYLerp.size()];
	}
	//�E�O
	else if (type == 1 && state >= legZLerp.size() / 2 + legZLerp.size() / 8) {
		legRotateZ = legZLerp[(state - legZLerp.size() / 2 - legZLerp.size() / 8) % legZLerp.size()];
		legRotateY = legYLerp[(state - legZLerp.size() / 2 - legZLerp.size() / 8) % legYLerp.size()];
	}
	//�����
	else if (type == 2 && state >= legZLerp.size() / 2 + legZLerp.size() / 4) {
		legRotateZ = legZLerp[(state - legZLerp.size() / 2 - legZLerp.size() / 4) % legZLerp.size()];
		legRotateY = legYLerp[(state - legZLerp.size() / 2 - legZLerp.size() / 4) % legYLerp.size()];
	}
	//�E���
	else if (type == 3 && state >= legZLerp.size() / 4) {
		legRotateZ = legZLerp[(state - legZLerp.size() / 4) % legZLerp.size()];
		legRotateY = legYLerp[(state - legZLerp.size() / 4) % legYLerp.size()];
	}
	state += 1;
}

void MiddleLegAnimator::ChangeAnimeType(int type)
{
	this->type = type;
}


