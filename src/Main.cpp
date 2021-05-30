
#include <stdlib.h>
#include <GL/glut.h>
#include "Spyder.h"
#include "Workspace.h"
#include "Camera.h"

static int shoulder = 0, elbow = 0, hand = 0;
static Camera camera;
static Workspace workspace;
static Spyder ant;

unsigned char	mouseFlag = GL_FALSE;		// flag for moving or not
int				xStart, yStart;				// start position when drug begins
double			xAngle = 0.0, yAngle = 0.0;	// angles of the teapot

// �������������܂Ƃ߂��֐�
void myInit(char* progname)
{
	// �f�B�X�v���C���[�h�̐錾
	// GLUT_DOUBLE �_�u���o�b�t�@�̎g�p��錾
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	// �E�B���h�E�T�C�Y�w��
	glutInitWindowSize(500, 500);
	// �E�B���h�E�̍���ʒu�̎w��
	glutInitWindowPosition(0, 0);
	// �E�B���h�E���� progname = �E�B���h�E�l�[��
	glutCreateWindow(progname);
	// �����F(?)
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void drawRobot() {
	glColor3d(1.0, 1.0, 1.0);
	glPushMatrix();
	/* 1st link */
	glRotated((double)shoulder, 0.0, 0.0, 1.0);
	glTranslated(1.0+shoulder, 0.0, 0.0);
	glPushMatrix();
	//
	glScaled(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	/* 2nd link */
	glTranslated(1.0, 0.0, 0.0);				//move to the end of 1st link
	glRotated((double)elbow, 0.0, 0.0, 1.0);
	glTranslated(1.0, 0.0, 0.0);

	glPushMatrix();
	glScaled(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	/*3rd link*/
	glTranslated(1.0, 0.0, 0.0);				//move to the end of 1st link
	glRotated((double)hand, 0.0, 0.0, 1.0);
	glTranslated(0.5, 0.0, 0.0);

	glPushMatrix();
	glScaled(1.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	/* 1st link */
	glRotated(-(double)shoulder, 0.0, 0.0, 1.0);
	glTranslated(-1.0, 0.0, 0.0);
	glPushMatrix();
	//
	glScaled(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();

	/* 2nd link */
	glTranslated(-1.0, 0.0, 0.0);				//move to the end of 1st link
	glRotated(-(double)elbow, 0.0, 0.0, 1.0);
	glTranslated(-1.0, 0.0, 0.0);

	glPushMatrix();
	glScaled(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	/*3rd link*/
	glTranslated(-1.0, 0.0, 0.0);				//move to the end of 1st link
	glRotated(-(double)hand, 0.0, 0.0, 1.0);
	glTranslated(-0.5, 0.0, 0.0);

	glPushMatrix();
	glScaled(1.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();

	glPopMatrix();

}

//�`��֐�
void myDisplay(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	
	glPushMatrix();
	{
		glRotated(xAngle, 1.0, 0.0, 0.0);
		glRotated(yAngle, 0.0, 1.0, 0.0);
		glPushMatrix();
		{
			camera.Draw();
			workspace.Draw();
			//ant.MovePosition(0.0, 0.0, -0.005);
			ant.Animation();
			ant.Draw();
		}
		glPopMatrix();
	}
	glPopMatrix();
	
	//glDisable(GL_DEPTH_TEST);
	
	// �o�b�N�o�b�t�@�̓��e���t�����g�o�b�t�@�ɓ]��
	glutSwapBuffers();
}

// 
void myReshape(int width, int height)
{
	glViewport(0, 0, width, height);
	// ���e�ϊ��s��X�^�b�N
	glMatrixMode(GL_PROJECTION);
	// �X�^�b�N�̍ŏ�ʂɒP�ʍs����i�[
	glLoadIdentity();
	// �������e�̐ݒ�(����p�A�c����A�O���N���b�v��(z)�A����N���b�v��(z) )
	// �X�^�b�N�̍ŏ�ʂɂ��̍s����i�[
	gluPerspective(90.0, (double)width / (double)height, 0.1, 100.0);
	// ���f���ϊ��s��X�^�b�N
	glMatrixMode(GL_MODELVIEW);
	// �X�^�b�N�̍ŏ�ʂɒP�ʍs����i�[
	glLoadIdentity();
}

// �L�[���͊֐�
void myKeyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
		shoulder = (shoulder + 5) % 360;
		camera.MovePosition(0, 0, 1);
		glutPostRedisplay();
		break;
	case 'W':
		shoulder = (shoulder - 5) % 360;
		camera.MovePosition(0, 0, 1);
		glutPostRedisplay();
		break;
	case 's':
		shoulder = (shoulder + 5) % 360;
		camera.MovePosition(0, 0, -1);
		glutPostRedisplay();
		break;
	case 'S':
		shoulder = (shoulder - 5) % 360;
		camera.MovePosition(0, 0, -1);
		glutPostRedisplay();
		break;
	case 'e':
		elbow = (elbow + 5) % 360;
		camera.MovePosition(0, -1, 0);
		glutPostRedisplay();
		break;
	case 'E':
		elbow = (elbow - 5) % 360;
		camera.MovePosition(0, -1, 0);
		glutPostRedisplay();
		break;
	case 'h':
		hand = (hand + 5) % 360;
		glutPostRedisplay();
		break;
	case 'H':
		hand = (hand - 5) % 360;
		glutPostRedisplay();
		break;
	case 'd':
		camera.MovePosition(1, 0, 0);
		glutPostRedisplay();
		break;
	case 'D':
		camera.MovePosition(1, 0, 0);
		glutPostRedisplay();
		break;
	case 'a':
		camera.MovePosition(-1, 0, 0);
		glutPostRedisplay();
		break;
	case 'A':
		camera.MovePosition(-1, 0, 0);
		glutPostRedisplay();
		break;
	case 'q':
		camera.MovePosition(0, 1, 0);
		glutPostRedisplay();
		break;
	case 'Q':
		camera.MovePosition(0, 1, 0);
		glutPostRedisplay();
		break;
	case '1':
		camera.ChangeCamera(0);
		break;
	case '2':
		camera.ChangeCamera(1);
		break;
	case '3':
		camera.ChangeCamera(2);
		break;
	case '4':
		camera.ChangeCamera(3);
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

// �C�x���g���Ȃ��ꍇ�ɌĂ΂��֐�
void myIdle(void)
{
	// �f�B�X�v���R�[���o�b�N�֐����Ă�
	// ���̃v���O�����̏ꍇ��myDisplay
	glutPostRedisplay();
}

void myMouseMotion(int x, int y)
{
	int		xdis, ydis;
	double	a = 0.5;

	if (mouseFlag == GL_FALSE) return;
	xdis = x - xStart;
	ydis = y - yStart;
	/* To match mouse's movement and its rotation axis */
	xAngle += (double)ydis * a;
	yAngle += (double)xdis * a;

	xStart = x;
	yStart = y;
	glutPostRedisplay();
}

void myMouseFunc(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		xStart = x;
		yStart = y;
		mouseFlag = GL_TRUE;
	}
	else {
		mouseFlag = GL_FALSE;
	}
}

int main(int argc, char** argv)
{
	// gult���C�u�����̏�����
	glutInit(&argc, argv);
	// ����������
	myInit(argv[0]);
	// 
	glutReshapeFunc(myReshape);
	// �L�[�{�[�h�A�}�E�X���͂̃R�[���o�b�N�֐��Z�b�g
	glutKeyboardFunc(myKeyboard);
	//
	glutMouseFunc(myMouseFunc);
	glutMotionFunc(myMouseMotion);
	// �C�x���g���Ȃ��ꍇ�ɌĂ΂��֐����Z�b�g 
	glutIdleFunc(myIdle);
	// �`��p�֐�(�f�B�X�v���C�R�[���o�b�N�֐�)�Z�b�g
	glutDisplayFunc(myDisplay);
	// �C�x���g�������[�v
	glutMainLoop();

	return 0;
}
