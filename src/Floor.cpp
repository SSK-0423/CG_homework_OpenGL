#include "Floor.h"
#include "GameData.h"
#include "Transform.hpp"

Texture* Floor::texture;

Floor::Floor() {
	texture = new Texture("textures/texture1.ppm");
}

Floor::~Floor() {
	delete texture;
}

void Floor::Update() {

}

void Floor::Draw() {
	texture->SetTexture();
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	{
		Position3D<float> position;
		Size3D<float> size;
		position = parent->GetComponent<Transform>()->GetPosition();
		size = parent->GetComponent<Transform>()->GetSize();
		glTranslated(position.x, position.y, position.z);
		glScaled(size.width, size.height, size.depth);
		glutSolidCube(1);
	}
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}