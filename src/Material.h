#pragma once
#include "Component.hpp"
#include "GameData.h"
#include <GL/glut.h>

typedef enum MATERIALOPTION {
	AMBIENT = 1,
	DIFFUSE = 1 << 1,
	SPECULAR = 1 << 2,
	EMISSION = 1 << 3,
	SHININESS = 1 << 4
};

class Material : public Component {
private:
	MaterialParam material;
public:
	Material();
	Material(MaterialParam mat);
	~Material();
	void EnableMaterial(const int& option);
	void SetMaterial(MaterialParam mat);
	MaterialParam GetMaterial();
};