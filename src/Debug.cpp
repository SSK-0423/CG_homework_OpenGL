#include "GL/glut.h"
//•¶Žš—ñ•\Ž¦
void DrawString(char buff[], float x, float y, float z)
{
	glRasterPos3d(x, y, z);
	for (char* p = buff; *p; p++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p);
	}
}