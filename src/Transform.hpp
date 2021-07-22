#pragma once
#include "GameData.h"
#include <stdio.h>
class Transform : public Component {
private:
	Position3D<float> position;
	Size3D<float> size;
	RotateAngle3D<float> angle;

public:
	Transform() {
		position.x = 0.0;
		position.y = 0.0;
		position.z = 0.0;
		size.width = 1.0;
		size.height = 1.0;
		size.depth = 1.0;
		angle.x = angle.y = angle.z = 0;
	}

	~Transform() {
		printf("Transform\n");
	}

	Position3D<float> GetPosition() {
		return position;
	}

	Size3D<float> GetSize() {
		return size;
	}

	RotateAngle3D<float> GetRotateAngle() {
		return angle;
	}

	void SetPosition(const float& x, const float& y, const float& z) {
		position.x = x;
		position.y = y;
		position.z = z;
	}

	void SetPosition(Position3D<float> pos) {
		position = pos;
	}

	void SetSize(const float& width, const float& height, const float& depth) {
		size.width = width;
		size.height = height;
		size.depth = depth;
	}

	void SetRotateAngle(const float& x, const float& y, const float& z) {
		angle.x = x;
		angle.y = y;
		angle.z = z;
		//printf("x:%f,y:%f,z:%f\n", x, y, z);
	}
	void AddRotateAngle(const float& x, const float& y, const float& z) {
		angle.x += x;
		angle.y += y;
		angle.z += z;
	}
	void Update() {}
	void Draw() {}
	void GetComponentName() {
		printf("Transform\n");
	}
};