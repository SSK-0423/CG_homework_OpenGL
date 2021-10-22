#include "Floor.h"
#include "GameData.h"

Texture* Floor::texture;

Floor::Floor(const char* filepath) {
	texture = new Texture(filepath);
	parentTransform = nullptr;
}

Floor::~Floor() {
	delete texture;
	delete parentTransform;
}

void Floor::Update() {

}

void Floor::Draw() {
	if (parentTransform == nullptr)
		parentTransform = parent->GetComponent<Transform>();

	texture->SetTexture();
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	{
		Position3D<float> position;
		Size3D<float> size;
		position = parentTransform->GetPosition();
		size = parentTransform->GetSize();
		glRotated(90, 1.0, 0.0, 0.0);
		glBegin(GL_QUADS);
		{
			glVertex3d(size.width / 2, -size.depth / 2, 0);
			glVertex3d(size.width / 2, size.depth / 2, 0);
			glVertex3d(-size.width / 2, size.depth / 2, 0);
			glVertex3d(-size.width / 2, -size.depth / 2, 0);
		}
		glEnd();
	}
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}