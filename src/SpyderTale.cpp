#include "SpyderTale.h"

void SpyderTale::DrawThread(float x, float y, float z, int angle)
{
	glPushMatrix();
	{
		glColor3d(1, 1, 1);
		glTranslated(0, 2, 0);
		glRotated(-angle, 0, 0, 1);
		glTranslated(0, 3, 0);
		glRotated(-90 - 30, 1, 0, 0);
		glTranslated(0, 0, 1.5);
		glScaled(0.1, 0.1, 12);
		glutSolidCube(1);
	}
	glPopMatrix();
}

void SpyderTale::Draw(float x, float y, float z) {
	glPushMatrix();
	{
		glTranslated(x, y, 5 / 2);
		glRotated(0, 1, 0, 0);
		glTranslated(x, y, z / 2);

		//DrawThread(0, 0, 0, 5);
		//DrawThread(0, 0, 0, 10);
		//DrawThread(0, 0, 0, 15);
		//DrawThread(0, 0, 0, 0);
		//DrawThread(0, 0, 0, -5);
		//DrawThread(0, 0, 0, -10);
		//DrawThread(0, 0, 0, -15);

		glColor3d(0.5, 0.25, 0);
		glScaled(4, 4, 5);
		glutSolidCube(1);
	}
	glPopMatrix();
}
void SpyderTale::Animation() {

}
void SpyderTale::SetPosition(float x, float y, float z) {

}