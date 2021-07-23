#include "PlayerLegAnimator.h"
#include <stdio.h>
PlayerLegAnimator::PlayerLegAnimator()
{
	cubicSpline.cubicSpline(firstJoint, firstJoint.size());
	MakeLerpList(firstLerp);
	cubicSpline.cubicSpline(secondJoint, secondJoint.size());
	MakeLerpList(secondLerp);
	cubicSpline.cubicSpline(thirdJoint, thirdJoint.size());
	MakeLerpList(thirdLerp);
	stat = 0;
	frameCount = 0;
}

PlayerLegAnimator::~PlayerLegAnimator()
{
}

void PlayerLegAnimator::MakeLerpList(std::vector<double>& list)
{
	printf("------------------------------------\n");
	for (int i = 0; i < 80; i++) {
		list.push_back(cubicSpline.interpolation(i, false));
		//printf("%lf\n", cubicSpline.interpolation(i, false));
	}
}

void PlayerLegAnimator::Animation(double& legRotateY, double& firstJointRotate, double& secondJointRotate, double& thirdJointRotate, bool inverse)
{
	int fps = 80;
	if (frameCount >= fps) {
		frameCount = 0;
		stat += 1;
	}
	if (inverse) {
		firstJointRotate = firstLerp[(frameCount + 40) % fps];
		secondJointRotate = secondLerp[(frameCount+40) % fps];
		thirdJointRotate = thirdLerp[(frameCount + 40) % fps];
	}
	else {
		firstJointRotate = firstLerp[frameCount];
		secondJointRotate = secondLerp[frameCount];
		thirdJointRotate = thirdLerp[frameCount];
	}
	frameCount++;
}
