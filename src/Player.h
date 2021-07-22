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
#include <GL/glut.h>

class Player : public ICharacter, public Component {
private:
	Camera camera;
	Transform* transform;
	Size3D<float> objSize;

	PlayerHead head;
	PlayerArm armRight;
	PlayerArm armLeft;
	PlayerWaist waist;
	PlayerLeg legRight;
	PlayerLeg legLeft;

	int size;
	bool myPlayer;
	//Vector3D forward;
	//Vector3D right;
	void DrawLocalAxis();
	void DrawPlayer();
public:
	Player(bool b);
	~Player();
	void Update();
	void Draw();
	void SetParentObject(Object& obj) override;
	void MoveForward(float dist);
	void MoveRight(float dist);
	void MoveUP(float dist);
	void Rotate(float angle);
	void ChangeObjectSize(int value);
};