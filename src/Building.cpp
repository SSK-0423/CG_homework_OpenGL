#include "Building.h"

Building::Building(const char* filepath) {
	texture = new Texture(filepath);
	parentTransform = nullptr;
}

Building::~Building() {
	delete texture;
	delete parentTransform;
}

void Building::Update()
{

}

void Building::Draw()
{
	if(parentTransform == nullptr) 
		parentTransform = parent->GetComponent<Transform>();

	texture->SetTexture();
	glPushMatrix();
	{
		Position3D<float> position;
		Size3D<float> size;
		position = parentTransform->GetPosition();
		size = parentTransform->GetSize();
		glTranslated(position.x, position.y, position.z);
		glScaled(size.width, size.height, size.depth);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
		{
			glVertex3d(0, 1, 0);
			glVertex3d(0, 0, 0);
			glVertex3d(1, 0, 0);
			glVertex3d(1, 1, 0);
		}
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
		{
			glVertex3d(0, 1, 1);
			glVertex3d(0, 0, 1);
			glVertex3d(1, 0, 1);
			glVertex3d(1, 1, 1);
		}
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
		{
			glVertex3d(1, 1, 1);
			glVertex3d(1, 0, 1);
			glVertex3d(1, 0, 0);
			glVertex3d(1, 1, 0);
		}
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
		{
			glVertex3d(0, 1, 1);
			glVertex3d(0, 0, 1);
			glVertex3d(0, 0, 0);
			glVertex3d(0, 1, 0);
		}
		glEnd();
		glDisable(GL_TEXTURE_2D);
		//glBegin(GL_QUADS);
		//{
		//	glVertex3d(0, 1, 0);
		//	glVertex3d(0, 1, 1);
		//	glVertex3d(1, 1, 1);
		//	glVertex3d(1, 1, 0);
		//}
		//glEnd();

	}
	glPopMatrix();
}
