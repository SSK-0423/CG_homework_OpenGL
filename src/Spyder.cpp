#include "Spyder.h"
#include "GL/glut.h"
#include <math.h>
#define PI 3.141592
Spyder::Spyder() {
	legRotateY = legRotateZ = 0;
	speed = 0.5;
	position.x = 0;
	position.y = 0;
	position.z = 0;
}

void Spyder::Draw() {
	glColor3d(0.5, 0.25, 0);
	// 最上位の単位行列をコピー
	glPushMatrix();
	{
		// 胴体
		glPushMatrix();
		{
			glTranslated(0, 2, position.z);
			{
				// 足
				float x = 4;

				DrawLeg(x, 0, -1, 4);
				DrawLeg(x, 0, -0.5, 1);
				DrawLeg(x, 0, 0, -1);
				DrawLeg(x, 0, 0.5, -3);
				DrawLeg(-x, 0, -1, 4);
				DrawLeg(-x, 0, -0.5, 1);
				DrawLeg(-x, 0, 0, -1);
				DrawLeg(-x, 0, 0.5, -3);

				// 頭
				DrawHead(0, 0, -2);
				// 尾
				DrawTale(0, 0, 4);
			}
			glScaled(4.0, 2.0, 3.0);
			glutWireCube(1);
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void Spyder::DrawHead(float x, float y, float z)
{
	// 頭
	glPushMatrix();
	{
		glColor3d(1, 0, 0);			//赤
		glTranslated(x, y, z);
		// 目
		DrawEye(-1.5, 0.5, -0.4, 0.4, 20, 20);
		DrawEye(-0.5, 0.5, -0.5, 0.45, 20, 20);
		DrawEye(0.5, 0.5, -0.5, 0.45, 20, 20);
		DrawEye(1.5, 0.5, -0.4, 0.4, 20, 20);

		glColor3d(0.3, 0.3, 0.3);
		// 触覚
		DrawTactile(1, -0.5, -1.5);
		DrawTactile(-1, -0.5, -1.5);
		glColor3d(0.5, 0.25, 0);
		glScaled(4, 3, 1);
		glutWireCube(1);
	}
	glPopMatrix();
}

void Spyder::DrawBody(float x, float y, float z)
{
	glPushMatrix();
	{

	}
	glPopMatrix();
}

void Spyder::DrawLeg(float x, float y, float z, int num)
{
	glPushMatrix();
	{
		//右足
		if (x > 0) {
			glTranslated(2, 0, 0);
			glRotated(30 * (sin(legRotateZ * (PI / 180))) / 2, 0, 0, 1);
			glRotated(15 * num + 15 * sin(legRotateY * (PI / 180)), 0, 1, 0);
			glRotated(30, 0, 0, 1);
			glTranslated(x / 2, y, z);
			glPushMatrix();
			{
				int sizeX = 3;
				glTranslated(2, 0, 0);
				glRotated(-90, 0, 0, 1);
				glTranslated(sizeX / 2.0f, 0, 0);
				glPushMatrix();
				{
					glPushMatrix();
					{
						glTranslated(sizeX / 2.0f, 0, 0);
						glRotated(-30, 0, 0, 1);
						glTranslated(1.0, 0, 0);
						glPushMatrix();
						{
							glColor3d(0.5, 0.4, 0);
							glScaled(2, 1, 0.5);
							glutWireCube(1);
							glColor3d(0.5, 0.25, 0);
						}
						glPopMatrix();
					}
					glPopMatrix();
					glScaled(sizeX, 1, 0.5);
					glutWireCube(1);
				}
				glPopMatrix();
			}
			glPopMatrix();
			glScaled(4, 1, 0.5);
			glutWireCube(1);
		}
		// 左足
		else {
			glTranslated(-2, 0, 0);
			glRotated(-30 * (sin((legRotateZ) * (PI / 180))) / 2, 0, 0, 1);
			glRotated(-15 * num - 15 * sin((legRotateY + 90) * (PI / 180)), 0, 1, 0);
			glRotated(-30, 0, 0, 1);
			glTranslated(x / 2, y, z);
			glPushMatrix();
			{
				int sizeX = 3;
				glTranslated(-2, 0, 0);
				glRotated(90, 0, 0, 1);
				glTranslated(-sizeX / 2.0f, 0, 0);
				glPushMatrix();
				{
					glPushMatrix();
					{
						glTranslated(-sizeX / 2.0f, 0, 0);
						glRotated(30, 0, 0, 1);
						glTranslated(-1.0, 0, 0);
						glPushMatrix();
						{
							glColor3d(0.5, 0.4, 0);
							glScaled(2, 1, 0.5);
							glutWireCube(1);
							glColor3d(0.5, 0.25, 0);
						}
						glPopMatrix();
					}
					glPopMatrix();
					glScaled(sizeX, 1, 0.5);
					glutWireCube(1);
				}
				glPopMatrix();
			}
			glPopMatrix();
			glScaled(4, 1, 0.5);
			glutWireCube(1);
		}

	}
	glPopMatrix();
}

// 尾の描画
void Spyder::DrawTale(float x, float y, float z)
{
	glPushMatrix();
	{
		glTranslated(x, y, 5 / 2);
		glRotated(-90, 1, 0, 0);
		glTranslated(x, y, z / 2);

		DrawThread(0,0,0,5);
		DrawThread(0,0,0,10);
		DrawThread(0,0,0,15);
		DrawThread(0,0,0,0);
		DrawThread(0,0,0,-5);
		DrawThread(0,0,0,-10);
		DrawThread(0,0,0,-15);

		glColor3d(0.5, 0.25, 0);
		glScaled(4, 2, 5);
		glutWireCube(1);
	}
	glPopMatrix();
}

// 目の描画
void Spyder::DrawEye(float x, float y, float z, double r, int slices, int stacks)
{
	// 目
	glPushMatrix();
	{
		glTranslated(x, y, z);
		glutWireSphere(r, slices, stacks);
	}
	glPopMatrix();
}

// 触覚の描画
void Spyder::DrawTactile(float x, float y, float z)
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
// 糸の描画
void Spyder::DrawThread(float x, float y, float z,int angle)
{
	glPushMatrix();
	{
		glColor3d(1, 1, 1);
		glTranslated(0, 2, 0);
		glRotated(-angle, 0, 0, 1);
		glTranslated(0, 3, 0);
		glRotated(-90-30, 1, 0, 0);
		glTranslated(0, 0, 1.5);
		glScaled(0.1, 0.1, 12);
		glutWireCube(1);

	}
	glPopMatrix();
}

void Spyder::MovePosition(float x, float y, float z)
{
	position.x += x;
	position.y += y;
	position.z += z;
}

// アニメーション
void Spyder::Animation()
{
	if (legRotateZ < 90) {
		legRotateZ += speed;
	}
	else if (legRotateZ >= 90 && legRotateY < 90){
		legRotateZ = 90;
		legRotateY += speed;
	}
	else if (legRotateY >= 90 && legRotateZ < 180){
		legRotateY = 90;
		legRotateZ += speed;
	}
	else if (legRotateZ >= 180 && legRotateY < 180){
		legRotateZ = 180;
		legRotateY += speed;
	}
	else {
		legRotateY = 0;
		legRotateZ = 0;
	}
}
