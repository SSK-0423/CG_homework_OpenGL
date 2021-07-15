#include "Building.h"
#include "Transform.hpp"

//ƒNƒ‰ƒX•Ï”ŽÀ‘Ì‰»
Texture* Building::texture;

Building::Building() {
	texture = new Texture("textures/texture1.ppm");
}

Building::~Building() {
	delete texture;
}

void Building::Update()
{

}

void Building::Draw()
{
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
