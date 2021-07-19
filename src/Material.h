#pragma once
#include "Component.hpp"
#include "GameData.h"
#include <GL/glut.h>

typedef enum MATERIALOPTION {
	AMBIENT = 1,
	DIFFUSE = 2,
	SPECULAR = 4,
	EMISSION = 8,
	SHININESS = 16
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