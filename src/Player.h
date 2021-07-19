#pragma once
#include "ICharacter.h"
#include "Component.hpp"
#include "Camera.h"
#include "GameData.h"
#include "Transform.hpp"
#include <GL/glut.h>
class Player : public ICharacter, public Component{
private:
	Camera camera;
	Transform* transform;
	void DrawLocalAxis();
public:
	Player();
	~Player();
	void Update();
	void Draw();
	void SetParentObject(Object& obj) override;
	void MoveForward(float dist);
	void MoveRight(float dist);
	void Rotate(float angle);
};