#include "Spyder.h"
#include "GL/glut.h"
#include <math.h>
#include "Debug.h"
#include "Lerp.h"
#define PI 3.141592

FrontLegAnimator Spyder::frontLegAni;
MiddleLegAnimator Spyder::middleLegAni;
HindLegAnimator Spyder::hindLegAni;

void Spyder::InitAnimation()
{
	//右脚
	leg[0].SetAnimator((Animator<double&, double&, double&, double&, float&>&)frontLegAni);
	leg[1].SetAnimator((Animator<double&, double&, double&, double&, float&>&)middleLegAni);
	leg[2].SetAnimator((Animator<double&, double&, double&, double&, float&>&)middleLegAni);
	leg[3].SetAnimator((Animator<double&, double&, double&, double&, float&>&)hindLegAni);

	//左脚
	leg[4].SetAnimator((Animator<double&, double&, double&, double&, float&>&)frontLegAni);
	leg[5].SetAnimator((Animator<double&, double&, double&, double&, float&>&)middleLegAni);
	leg[6].SetAnimator((Animator<double&, double&, double&, double&, float&>&)middleLegAni);
	leg[7].SetAnimator((Animator<double&, double&, double&, double&, float&>&)hindLegAni);
}

void Spyder::MoveAnimation()
{
	DebugDraw();
	position.x = xLerp[state % xLerp.size()];
	position.z = zLerp[state % zLerp.size()];
	state += 1;
	if (position.x == 0.0f && position.z == -30.0f ||
		position.x == 30.0f && position.z == -30.0f ||
		position.x == 30.0f && position.z == 30.0f ||
		position.x == -30.0f && position.z == 30.0f ||
		position.x == -30.0f && position.z == 0.0f) {
		angle -= 90;
	}
	if (position.x == 0.0f && position.z == 0.0f) {
		angle = 0;
	}
}

void Spyder::DebugDraw()
{
	char buff[64];
	sprintf_s(buff, "x:%f", position.x);
	DrawString(buff, position.x, position.y, position.z + 2);
	sprintf_s(buff, "y:%f", position.y);
	DrawString(buff, position.x, position.y, position.z);
	sprintf_s(buff, "z:%f", position.z);
	DrawString(buff, position.x, position.y, position.z - 2);
}

Spyder::Spyder() {
	angle = 0;
	state = 0;
	position.x = 0;
	position.y = 0;
	position.z = 0;
	MakeLerpList(x, xLerp, 300);
	MakeLerpList(z, zLerp, 300);
	InitAnimation();
}

void Spyder::Draw() {
	//茶色
	glColor3d(0.5, 0.25, 0);
	// 最上位の単位行列をコピー
	glPushMatrix();
	{
		// 胴体
		glPushMatrix();
		{
			glTranslated(position.x, 2, position.z);
			glRotated(angle, 0, 1, 0);
			{
				// 足
				float x = 4;
				//右脚
				leg[0].Draw(x, 0, -1, 4);
				leg[1].Draw(x, 0, -0.5, 2);
				leg[2].Draw(x, 0, 0, -2);
				leg[3].Draw(x, 0, 0.5, -4);

				//左脚
				leg[4].Draw(-x, 0, -1, 4);
				leg[5].Draw(-x, 0, -0.5, 2);
				leg[6].Draw(-x, 0, 0, -2);
				leg[7].Draw(-x, 0, 0.5, -4);

				// 頭
				head.Draw(0, 0, -2);

				// 尾
				tale.Draw(0, 0, 4);
			}
			glScaled(4.0, 2.0, 3.0);
			glutSolidCube(1);
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void Spyder::MovePosition(float x, float y, float z)
{
	position.x += x;
	position.y += y;
	position.z += z;
}

void Spyder::Rotate(int angle)
{
	this->angle = angle;
}
int Spyder::GetAngle() {
	return angle;
}
// 各パーツのアニメーション呼び出し
void Spyder::Animation() {

	// 前脚のアニメーション
	frontLegAni.ChangeAnimeType(0);
	leg[0].Animation();
	frontLegAni.ChangeAnimeType(1);
	leg[4].Animation();

	// 胴体中央の脚のアニメーション
	// 中央右前脚
	middleLegAni.ChangeAnimeType(1);
	leg[1].Animation();
	// 中央左前脚
	middleLegAni.ChangeAnimeType(0);
	leg[5].Animation();

	//中央右後ろ脚
	middleLegAni.ChangeAnimeType(3);
	leg[2].Animation();
	//中央左後ろ脚
	middleLegAni.ChangeAnimeType(2);
	leg[6].Animation();

	//後ろ脚のアニメーション
	hindLegAni.ChangeAnimeType(1);
	leg[3].Animation();
	hindLegAni.ChangeAnimeType(0);
	leg[7].Animation();

	MoveAnimation();
}