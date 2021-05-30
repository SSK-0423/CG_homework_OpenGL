#include "Spyder.h"
#include "GL/glut.h"
#include <math.h>
#define PI 3.141592

FrontLegAnimator Spyder::frontLegAni;
MiddleLegAnimator Spyder::middleLegAni;

void Spyder::InitAnimation()
{
	//�E�r
	leg[0].SetAnimator((Animator<double&,double&,float&>&)frontLegAni);
	leg[1].SetAnimator((Animator<double&, double&, float&>&)middleLegAni);
	leg[2].SetAnimator((Animator<double&, double&, float&>&)middleLegAni);
	leg[3].SetAnimator((Animator<double&, double&, float&>&)frontLegAni);
	
	//���r
	leg[4].SetAnimator((Animator<double&, double&, float&>&)frontLegAni);
	leg[5].SetAnimator((Animator<double&, double&, float&>&)middleLegAni);
	leg[6].SetAnimator((Animator<double&, double&, float&>&)middleLegAni);
	leg[7].SetAnimator((Animator<double&, double&, float&>&)frontLegAni);
}

Spyder::Spyder() {
	position.x = 0;
	position.y = 0;
	position.z = 0;
	InitAnimation();
}

void Spyder::Draw() {
	//���F
	glColor3d(0.5, 0.25, 0);
	// �ŏ�ʂ̒P�ʍs����R�s�[
	glPushMatrix();
	{
		// ����
		glPushMatrix();
		{
			glTranslated(0, 2, position.z);
			{
				// ��
				float x = 4;
				//�E�r
				leg[0].Draw(x, 0, -1, 4);
				leg[1].Draw(x, 0, -0.5, 1);
				leg[2].Draw(x, 0, 0, -1);
				leg[3].Draw(x, 0, 0.5, -3);

				//���r
				leg[4].Draw(-x, 0, -1, 4);
				leg[5].Draw(-x, 0, -0.5, 1);
				leg[6].Draw(-x, 0, 0, -1);
				leg[7].Draw(-x, 0, 0.5, -3);

				// ��
				head.Draw(0, 0, -2);

				// ��
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

// �e�p�[�c�̃A�j���[�V�����Ăяo��
void Spyder::Animation() {
	for (int i = 0; i < 8; i++) {
		leg[i].Animation();
	}
	head.Animation();
	tale.Animation();
}