#pragma once
#include <stdio.h>
#include <GL/glut.h>
#include "Component.hpp"
#define imageWidth 256
#define imageHeight 256

class Texture : public Component {
private:
	unsigned char texImage[imageHeight][imageWidth][3];
public:
	Texture(const char* filepath);
	~Texture();
	void Update();
	void Draw();
	void ReadPPMImage(const char* filepath);
	void SetTexture();
};