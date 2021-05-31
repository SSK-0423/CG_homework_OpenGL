#include "Stage.h"
#include "GL/glut.h"
void Stage::DrawBuilding(double x, double y, double z, double sizeX, double sizeY, double sizeZ)
{
	glPushMatrix();
	{
		glTranslated(x,y,z);
		glScaled(sizeX,sizeY,sizeZ);
		glutWireCube(1);
	}
	glPopMatrix();
}
void Stage::Draw() {
	DrawBuilding(10, 7.5, -10, 5, 15, 5);
	DrawBuilding(17, 7.5, -10, 5, 15, 5);
	DrawBuilding(-10, 7.5, -10, 5, 15, 5);
	DrawBuilding(-17, 7.5, -10, 5, 15, 5);
}