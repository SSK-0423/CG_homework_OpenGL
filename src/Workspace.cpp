#include "Workspace.h"
#include "GL/glut.h"

Workspace::Workspace() {
	axesLength = 10;
}

Workspace::Workspace(int length) {
	axesLength = length;
}

void Workspace::Draw() {
	DrawXYZAxes();
	DrawFloor();
}

void Workspace::DrawXYZAxes() {
	// XYZŽ²‚Ì•`‰æ
	glBegin(GL_LINES);
	{
		glColor3d(1.0, 1.0, 0.0);	// yellow
		glVertex3d(0.0, 0.0, 0.0); glVertex3d(axesLength, 0.0, 0.0);	//x-axis
		glColor3d(1.0, 0.0, 0.0);	// red
		glVertex3d(0.0, 0.0, 0.0); glVertex3d(0.0, axesLength, 0.0);	//y-axis
		glColor3d(0.0, 0.0, 1.0);	// blue
		glVertex3d(0.0, 0.0, 0.0); glVertex3d(0.0, 0.0, axesLength);	//z-axis
	}
	glEnd();
}

void Workspace::DrawFloor()
{
	glColor3d(1.0, 1.0, 1.0);		// draw floor
	glBegin(GL_LINES);
	for (int i = -35; i < 36; i += 2) {
		glVertex3i(i, 0, -35);
		glVertex3i(i, 0, 35);
		glVertex3i(-50, 0, i);
		glVertex3i(50, 0, i);
	}
	glEnd();
}
