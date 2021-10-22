#pragma once
#include "BodyPart.h"
#include "Texture.h"
#include "Material.h"

class SpyderHead : public BodyPart<float,float,float> {
private:
	Texture* eyeTexture;
	Material eyeMaterial;
	MaterialParam eyeParam = {
		{0.5,0.2,0.2,1.0},
		{0.5,0.0,0.0,1.0},
		{0.0,0.0,0.0,1.0},
		{0.0,0.0,0.0,1.0},
		0
	};
	Material bodyMaterial;
	MaterialParam bodyParam = {
		{0.2,0.2,0.2,1.0},
		{0.53,0.29,0.17,1.0},
		{0.0,0.0,0.0,1.0},
		{0.0,0.0,0.0,1.0},
		0
	};
	Material tactileMaterial;
	MaterialParam tactileParam = {
		{0.2,0.2,0.2,1.0},
		{0.2,0.2,0.2,1.0},
		{0.0,0.0,0.0,1.0},
		{0.0,0.0,0.0,1.0},
		0
	};
	float mtr[2][4] = {
		{0.5,0.0,0.0,0.0},
		{1.0,0.0,0.0,0.0},
	};
	// ñ⁄
	void DrawEye(float x, float y, float z, double r, int slices, int stacks);
	// êGäo
	void DrawTactile(float x, float y, float z);
public:
	SpyderHead();
	void Draw(float x, float y, float z);
	void Animation();
	void SetPosition(float x, float y, float z);
};