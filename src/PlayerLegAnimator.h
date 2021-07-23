#pragma once
#include "Animator.h"
#include "CubicSpline.hpp"
#include <vector>

class PlayerLegAnimator : public Animator<double&, double&, double&, double&, bool> {
private:
	std::vector<std::vector<double>> firstJoint = { {0,-30},{10,-45},{20,-15},{30,15},{40,30}, {50,10},{60,-5},{70,-25},{80,-30} };	// å“ä÷êﬂ
	std::vector<double> firstLerp;
	
	std::vector<std::vector<double>> secondJoint = { {0,0},{10,45},{20,15},{30,5},{40,15},{50,90},{60,90},{70,30},{80,0} };	// ïG
	std::vector<double> secondLerp;
	
	std::vector<std::vector<double>> thirdJoint = { {0,0},{10,0},{20,0},{30,0},{40,0},{50,5},{60,0},{70,0},{80,0} };	// ë´éÒ
	std::vector<double> thirdLerp;
	
	int stat;
	int frameCount;
public:
	CubicSpline cubicSpline;	// ÉXÉvÉâÉCÉìï‚ä‘
	PlayerLegAnimator();
	~PlayerLegAnimator();
	void MakeLerpList(std::vector<double>& list);
	void Animation(double& legRotateY, double& firstJointRotate, double& secondJointRotate, double& thirdJointRotate, bool inverse);
};