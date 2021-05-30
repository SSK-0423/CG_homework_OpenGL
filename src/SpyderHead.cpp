#include "SpyderHead.h"
void SpyderHead::DrawEye(float x, float y, float z, double r, int slices, int stacks)
{
	// ñ⁄
	glPushMatrix();
	{
		glTranslated(x, y, z);
		glutWireSphere(r, slices, stacks);
	}
	glPopMatrix();
}

void SpyderHead::DrawTactile(float x, float y, float z)
{
	glPushMatrix();
	{
		glTranslated(0, 0, -0.5);
		glRotated(-15, 1, 0, 0);
		glTranslated(x, y, -0.5);
		glPushMatrix();
		{
			glColor3d(0.5, 0.5, 0);
			glTranslated(0, 0, -0.5);
			glRotated(-90, 1, 0, 0);
			glTranslated(0, 0, -0.75);
			glScaled(0.5, 0.5, 1.5);
			glutWireCube(1);
		}
		glPopMatrix();
		glColor3d(0.3, 0.3, 0.3);
		glScaled(0.5, 0.5, 1);
		glutWireCube(1);
	}
	glPopMatrix();
}

void SpyderHead::Draw(float x, float y, float z) {
	glPushMatrix();
	{
		glColor3d(1, 0, 0);			//ê‘
		glTranslated(x, y, z);
		// ñ⁄
		DrawEye(-1.5, 0.5, -0.4, 0.4, 20, 20);
		DrawEye(-0.5, 0.5, -0.5, 0.45, 20, 20);
		DrawEye(0.5, 0.5, -0.5, 0.45, 20, 20);
		DrawEye(1.5, 0.5, -0.4, 0.4, 20, 20);

		glColor3d(0.3, 0.3, 0.3);
		// êGäo
		DrawTactile(1, -0.5, -1.5);
		DrawTactile(-1, -0.5, -1.5);
		glColor3d(0.5, 0.25, 0);
		glScaled(4, 3, 1);
		glutWireCube(1);
	}
	glPopMatrix();
}
void SpyderHead::Animation() {

}
void SpyderHead::SetPosition(float x, float y, float z) {

}