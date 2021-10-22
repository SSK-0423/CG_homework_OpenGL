#include "Building.h"
#include "Cross.h"
Building::Building(const char* filepath) {
	texture = new Texture(filepath);
	material = new Material();
	parentTransform = nullptr;
	material->SetMaterial(param);
}

Building::~Building() {
	delete texture;
	delete material;
	delete parentTransform;
}

void Building::Update()
{

}

void Building::Draw()
{
	if (parentTransform == nullptr)
		parentTransform = parent->GetComponent<Transform>();

	texture->SetTexture();
	material->EnableMaterial(AMBIENT | DIFFUSE);
	glPushMatrix();
	{
		Position3D<float> position;
		Size3D<float> size;
		position = parentTransform->GetPosition();
		size = parentTransform->GetSize();
		//material->EnableMaterial(31);
		glTranslated(position.x, position.y, position.z);
		glScaled(size.width, size.height, size.depth);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
		{
			float normal[3];
			Cross(vec[0], vec[1], normal);
			glNormal3b(normal[0],normal[1],normal[2]);
			glVertex3d(0, 1, 0);	//ç∂è„
			glVertex3d(0, 0, 0);	//ç∂â∫
			glVertex3d(1, 0, 0);	//âEâ∫
			glVertex3d(1, 1, 0);	//âEè„
			glDisable(GL_TEXTURE_2D);

			glEnable(GL_TEXTURE_2D);
			Cross(vec[2], vec[3], normal);
			glNormal3b(normal[0], normal[1], normal[2]);
			glVertex3d(0, 1, 1);
			glVertex3d(0, 0, 1);
			glVertex3d(1, 0, 1);
			glVertex3d(1, 1, 1);
			glDisable(GL_TEXTURE_2D);

			Cross(vec[4], vec[5], normal);
			glNormal3b(normal[0], normal[1], normal[2]);
			glEnable(GL_TEXTURE_2D);
			glNormal3d(1, 0, 0);
			glVertex3d(1, 1, 1);
			glVertex3d(1, 0, 1);
			glVertex3d(1, 0, 0);
			glVertex3d(1, 1, 0);
			glDisable(GL_TEXTURE_2D);

			Cross(vec[6], vec[7], normal);
			glNormal3b(normal[0], normal[1], normal[2]);
			glEnable(GL_TEXTURE_2D);
			glNormal3b(0, 1, 0);
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
