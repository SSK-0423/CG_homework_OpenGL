#include <stdlib.h>
#include <GL/glut.h>
#include "Spyder.h"
#include "Workspace.h"
#include "Camera.h"
#include "Stage.h"
#include "GameObject.hpp"
#include "ComponentSystem.hpp"
#include "Debug.h"
#include "FPS.h"

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500
static Camera camera;
static Workspace workspace;
static Spyder spyder;
static Stage stage;
static GameObject* obj;
static FPS fps;
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
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	// �E�B���h�E�̍���ʒu�̎w��
	glutInitWindowPosition(0, 0);
	// �E�B���h�E���� progname = �E�B���h�E�l�[��
	glutCreateWindow(progname);
	// �����F(?)
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

//�`��֐�
void myDisplay(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_LIGHTING);
	glPushMatrix();
	{
		glRotated(xAngle, 1.0, 0.0, 0.0);
		glRotated(yAngle, 0.0, 1.0, 0.0);
		glPushMatrix();
		{
			camera.SetPosition(spyder.position.x, spyder.position.y + 5, spyder.position.z - 15);
			camera.SetViewPosition(spyder.position.x, spyder.position.y, spyder.position.z - 1);
			camera.Rotate(spyder.GetAngle());
			camera.Draw();
			workspace.Draw();
			//spyder.Animation();
			//spyder.Draw();
			glColor3d(1, 1, 1);
			stage.Draw();
		}
		glPopMatrix();
	}
	glPopMatrix();

	glLoadIdentity();
	char buff[64];
	sprintf_s(buff, "FPS:%.1f", fps.GetFPS());
	DrawString(buff, -1, 0.9, -1);

	glDisable(GL_DEPTH_TEST);

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
		camera.MovePosition(0, 0, 1);
		glutPostRedisplay();
		break;
	case 'W':
		camera.MovePosition(0, 0, 1);
		glutPostRedisplay();
		break;
	case 's':
		camera.MovePosition(0, 0, -1);
		glutPostRedisplay();
		break;
	case 'S':
		camera.MovePosition(0, 0, -1);
		glutPostRedisplay();
		break;
	case 'e':
		camera.MovePosition(0, -1, 0);
		glutPostRedisplay();
		break;
	case 'E':
		camera.MovePosition(0, -1, 0);
		glutPostRedisplay();
		break;
	case 'h':
		glutPostRedisplay();
		break;
	case 'H':
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
	fps.Update();
	glutPostRedisplay();
	fps.Wait();
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

void mySetLight()
{
	float light0_position[] = { 1.0,  1.0, 1.0, 1.0 };	// point light source
	float light1_position[] = { -1.0, -1.0, 1.0, 1.0 };	// point light source
	float light1_ambient[] = { 0.0, 1.0, 0.0, 1.0 };
	float light1_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };
	float light1_specular[] = { 0.0, 1.0, 0.0, 1.0 };

	/* Set up LIGHT0 which uses the default parameters except position */
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	/* Set up LIGHT1 */
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);

	glEnable(GL_LIGHT0);		// enable the 0th light
	glEnable(GL_LIGHT1);		// enable the 1st light
}

int main(int argc, char** argv)
{
	// gult���C�u�����̏�����
	glutInit(&argc, argv);
	// ����������
	myInit(argv[0]);
	// ���C�g�̐ݒ�
	mySetLight();
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

	fps.SetFPS(60);
	// �C�x���g�������[�v
	glutMainLoop();

	return 0;
}
