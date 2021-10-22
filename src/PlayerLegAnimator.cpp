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

PlayerLegAnimator::PlayerLegAnimator(int value)
{
	ChangeAnimeSpeed(value);
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

void PlayerLegAnimator::ChangeAnimeSpeed(int frame)
{
	animeSpeed = (float)frame / 80;
	for (int i = 0; i < firstJoint.size(); i++) {
		firstJoint[i][0] *= animeSpeed;
		secondJoint[i][0] *= animeSpeed;
		thirdJoint[i][0] *= animeSpeed;
	}
}

void PlayerLegAnimator::MakeLerpList(std::vector<double>& list)
{
	printf("------------------------------------\n");
	for (int i = 0; i < 80; i++) {
		list.push_back(cubicSpline.interpolation(i, false));
		//printf("%lf\n", cubicSpline.interpolation(i, false));
	}
}

void PlayerLegAnimator::Animation(double& legRotateY, double& firstJointRotate, double& secondJointRotate, double& thirdJointRotate, bool inverse,int fps,int animeType)
{
	if (frameCount >= fps) {
		frameCount = 0;
	}
	if (animeType == 0)
	{
		if (inverse) {
			firstJointRotate = firstLerp[(frameCount + fps / 2) % fps];
			secondJointRotate = secondLerp[(frameCount + fps / 2) % fps];
			thirdJointRotate = thirdLerp[(frameCount + fps / 2) % fps];
		}
		else {
			firstJointRotate = firstLerp[frameCount];
			secondJointRotate = secondLerp[frameCount];
			thirdJointRotate = thirdLerp[frameCount];
		}
	}
	
	if (animeType == 1) {

		const int LISTMAX = fps - 1;
		
		if (inverse) {
			firstJointRotate = firstLerp[LISTMAX - (frameCount + fps / 2) % fps] ;
			secondJointRotate = secondLerp[LISTMAX- (frameCount + fps / 2) % fps];
			thirdJointRotate = thirdLerp[LISTMAX - (frameCount + fps / 2) % fps];
		}
		else {
			firstJointRotate = firstLerp[LISTMAX - frameCount];
			secondJointRotate = secondLerp[LISTMAX - frameCount];
			thirdJointRotate = thirdLerp[LISTMAX - frameCount];
		}
	}
	frameCount++;
}