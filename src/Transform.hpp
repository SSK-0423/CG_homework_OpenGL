#pragma once
#include "GameData.h"

class Transform : public Component {
private:
	Position3D<float> position;
	Size3D<float> size;

public:
	Transform() {
		position.x = 0.0;
		position.y = 0.0;
		position.z = 0.0;
		size.width = 1.0;
		size.height = 1.0;
		size.depth = 1.0;
	};

	~Transform() {};

	Position3D<float> GetPosition() {
		return position;
	}

	Size3D<float> GetSize() {
		return size;
	}

	void SetPosition(const float& x, const float& y, const float& z) {
		position.x = x;
		position.y = y;
		position.z = z;
	}

	void SetSize(const float& width, const float& height, const float& depth) {
		size.width = width;
		size.height = height;
		size.depth = depth;
	}

	void Update() {}
	void Draw() {}
};