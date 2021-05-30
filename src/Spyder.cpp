#include "Spyder.h"
#include "GL/glut.h"
#include <math.h>
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

Spyder::Spyder() {
	position.x = 0;
	position.y = 0;
	position.z = 0;
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
			glTranslated(0, 2, position.z);
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
			glutWireCube(1);
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

	head.Animation();
	tale.Animation();
}