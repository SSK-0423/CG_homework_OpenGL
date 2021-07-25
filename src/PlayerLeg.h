#pragma once
#include "BodyPart.h"
#include "Animator.h"
#include "PlayerLegAnimator.h"
#include "Texture.h"
#include "Material.h"

class PlayerLeg : public BodyPart<const float&, const float&, const float&, bool, int>
{
private:
	Texture* legTexture;
	Texture* toesTexture;
	Material material;
	MaterialParam param = {
		{0.0,0.0,0.7,1.0},
		{0.0,0.0,0.7,1.0},
		{0.0,0.0,0.0,1.0},
		{0.0,0.0,0.0,1.0},
		0
	};
	Material material2;
	MaterialParam param2 = {
		{0.2,0.2,0.2,1.0},
		{0.2,0.2,0.2,1.0},
		{0.0,0.0,0.0,1.0},
		{0.0,0.0,0.0,1.0},
		0
	};
	// ÉAÉjÉÅÅ[É^Å[
	Animator<double&, double&, double&, double&, bool, int,int>* animator;
	// Xé≤âÒì]
	double legRotateX;
	// å“ä÷êﬂÇÃäpìx
	double firstJointRotate;
	// ïGÇÃäpìx
	double secondJointRotate;
	// ë´éÒÇÃäpìx
	double thirdJointRotate;
public:
	PlayerLeg();
	~PlayerLeg();
	void Draw(const float& x, const float& y, const float& z,bool inv,int state);
	void Animation();
	void Animation(bool inverse,int fps, int animeType);
	void SetPosition(float x, float y, float z);
	void AddAngle(float value, int num);
	void StopAnime();
};