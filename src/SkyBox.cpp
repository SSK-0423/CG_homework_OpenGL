#include "SkyBox.h"

SkyBox::SkyBox() {
	texture = new Texture("textures/sky.ppm");
}
SkyBox::~SkyBox() {

}

void SkyBox::Update() {

}

void SkyBox::Draw() {
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	{
		glutSolidSphere(10,100,100);
	}
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}