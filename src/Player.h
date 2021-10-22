#pragma once
#include "ICharacter.h"
#include "Component.hpp"
#include "Camera.h"
#include "GameData.h"
#include "Transform.hpp"
#include "PlayerHead.h"
#include "PlayerArm.h"
#include "PlayerWaist.h"
#include "PlayerLeg.h"
#include "CubicSpline.hpp"
#include "Texture.h"
#include "Material.h"
#include <vector>
#include <GL/glut.h>

class Player : public ICharacter, public Component {
private:
	Camera camera;
	Transform* transform;
	Size3D<float> objSize;
	Texture* bodyTexture;

	PlayerHead head;
	PlayerArm armRight;
	PlayerArm armLeft;
	PlayerWaist waist;
	PlayerLeg legRight;
	PlayerLeg legLeft;

	CubicSpline cubicSpline;

	Material material;
	std::vector<std::vector<double>> playerY = { {0,-0.2},{10 ,-0.2},{20 ,-0.1},{30 ,0},{40 ,-0.2},
												 {50 ,-0.2},{60 ,-0.1},{70 ,0},{80 ,-0.2} };
	std::vector<double> yLerp;
	int size;
	bool myPlayer;
	int frameCount;
	int animeFrame;
	float animeSpeed;
	double down;
	CAMERATYPE cameraType;

	//Vector3D forward;
	//Vector3D right;
	void DrawLocalAxis();
	void DrawPlayer();
	void MakeLerpList(std::vector<double>& list);
public:
	Player(bool b);
	~Player();
	void Update();
	void Draw();
	void SetParentObject(Object& obj) override;
	void Animation();
	void BackAnimation();
	void MoveForward(float dist);
	void MoveRight(float dist);
	void MoveUP(float dist);
	void Rotate(float angle);
	void ChangeObjectSize(int value);
	void LegRotate(float value, int num);
	void DrawAnimeState();
	void ChangeAnimeSpeed(int frame);
	void StopAnime();
	void DebugDraw();
	void ChangeCamera(CAMERATYPE type);
	int animeState;
};