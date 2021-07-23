#include "PlayerLeg.h"

PlayerLeg::PlayerLeg()
{
	animator = new PlayerLegAnimator();
	legRotateX = 0;
	firstJointRotate = 0;
	secondJointRotate = 0;
	thirdJointRotate = 0;
}

PlayerLeg::~PlayerLeg()
{
}
// ¶F‰E
void PlayerLeg::Draw(const float& x, const float& y, const float& z, bool inv, int state)
{
	glPushMatrix();
	{
		glTranslated(x * size, y * size * 1.5, z * size);
		//switch (state)
		//{
		//case 0:
		//	if (inv) glRotated(30, 1, 0, 0); else glRotated(-30, 1, 0, 0);	//Contact(reverse)
		//	break;
		//case 1:
		//	if (inv) glRotated(10, 1, 0, 0); else glRotated(-45, 1, 0, 0);	//down
		//	break;
		//case 2:
		//	if (inv) glRotated(-5, 1, 0, 0); else glRotated(-15, 1, 0, 0);	//Passing
		//	break;
		//case 3:
		//	if (inv) glRotated(-25, 1, 0, 0); else glRotated(15, 1, 0, 0);	//up
		//	break;
		//case 4:
		//	if (inv) glRotated(-30, 1, 0, 0); else glRotated(30, 1, 0, 0);	//Contact
		//	break;
		//case 5:
		//	if (inv) glRotated(-45, 1, 0, 0); else glRotated(10, 1, 0, 0);	//down
		//	break;
		//case 6:
		//	if (inv) glRotated(-15, 1, 0, 0); else glRotated(-5, 1, 0, 0);	//Passing
		//	break;
		//case 7:
		//	if (inv) glRotated(15, 1, 0, 0); else glRotated(-25, 1, 0, 0);	//up
		//	break;
		//default:
		//	break;
		//}
		glRotated(firstJointRotate, 1, 0, 0);
		glTranslated(0, -y * size * 0.5, z * size);
		glPushMatrix();
		{
			glPushMatrix();
			{
				glTranslated(0, -(1) * (float)size / 2, 0);
				//switch (state)
				//{
				//case 0:
				//	if (inv) glRotated(15, 1, 0, 0); else glRotated(0, 1, 0, 0);	// Contact
				//	break;
				//case 1:
				//	if (inv) glRotated(90, 1, 0, 0); else glRotated(45, 1, 0, 0);	//down
				//	break;
				//case 2:
				//	if (inv) glRotated(90, 1, 0, 0); else glRotated(15, 1, 0, 0);	//Passing
				//	break;
				//case 3:
				//	if (inv) glRotated(30, 1, 0, 0); else glRotated(5, 1, 0, 0);	//up
				//	break;
				//case 4:
				//	if (inv) glRotated(0, 1, 0, 0); else glRotated(15, 1, 0, 0);	//Contact
				//	break;
				//case 5:
				//	if (inv) glRotated(45, 1, 0, 0); else glRotated(90, 1, 0, 0);	//down
				//	break;
				//case 6:
				//	if (inv) glRotated(15, 1, 0, 0); else glRotated(90, 1, 0, 0);	//Passing
				//	break;
				//case 7:
				//	if (inv) glRotated(5, 1, 0, 0); else glRotated(30, 1, 0, 0);	//up
				//	break;
				//default:
				//	break;
				//}
				glRotated(secondJointRotate, 1, 0, 0);
				glTranslated(0, -(1) * (float)size / 2, 0);
				glPushMatrix();
				{
					glTranslated(0, -(0.5 + 0.125) * (float)size / 2, 0.125 * (float)size / 2);
					//switch (state)
					//{
					//case 0:
					//	if (inv) glRotated(0, 1, 0, 0); else glRotated(0, 1, 0, 0);		//Contact
					//	break;
					//case 1:
					//	if (inv) glRotated(5, 1, 0, 0); else glRotated(0, 1, 0, 0);	//down
					//	break;
					//case 2:
					//	if (inv) glRotated(0, 1, 0, 0); else glRotated(0, 1, 0, 0);	//passing
					//	break;
					//case 3:
					//	if (inv) glRotated(0, 1, 0, 0); else glRotated(0, 1, 0, 0);		//up
					//	break;
					//case 4:
					//	if (inv) glRotated(0, 1, 0, 0); else glRotated(0, 1, 0, 0);		//contact
					//	break;
					//case 5:
					//	if (inv) glRotated(0, 1, 0, 0); else glRotated(5, 1, 0, 0);	//down
					//	break;
					//case 6:
					//	if (inv) glRotated(0, 1, 0, 0); else glRotated(0, 1, 0, 0);	//passing
					//	break;
					//case 7:
					//	if (inv) glRotated(0, 1, 0, 0); else glRotated(0, 1, 0, 0);		//up
					//default:
					//	break;
					//}
					glRotated(thirdJointRotate, 1, 0, 0);
					glTranslated(0, -(0.5 + 0.125) * (float)size / 2, 0.125 * (float)size / 2);
					glScaled(0.4 * size, 0.25 * size, 0.75 * size);
					glutWireCube(1);	// ‘«æ
				}
				glPopMatrix();
				glScaled(0.5 * size, 1 * size, 0.5 * size);
				glutWireCube(1);	// ‚·‚Ë
			}
			glPopMatrix();
			glScaled(0.5 * size, 1 * size, 0.5 * size);
			glutWireCube(1);	// ‘¾‚à‚à
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void PlayerLeg::Animation()
{
}

void PlayerLeg::Animation(bool inverse)
{
	animator->Animation(legRotateX, firstJointRotate, secondJointRotate, thirdJointRotate, inverse);
}

void PlayerLeg::SetPosition(float x, float y, float z)
{
}

void PlayerLeg::AddAngle(float value, int num)
{
	switch (num)
	{
	case 1:
		firstJointRotate += value;
		break;
	case 2:
		secondJointRotate += value;
		break;
	case 3:
		thirdJointRotate += value;
		break;
	default:
		break;
	}
}
