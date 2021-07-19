#pragma once
#include <GL/glut.h>

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

class OpenGLInit{
private:
public:

};
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

void myKeyboard(unsigned char key, int x, int y)
{

}

// �C�x���g���Ȃ��ꍇ�ɌĂ΂��֐�
void myIdle(void)
{
	// �f�B�X�v���R�[���o�b�N�֐����Ă�
	// ���̃v���O�����̏ꍇ��myDisplay
	glutPostRedisplay();
}

//�`��֐�
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_DEPTH_TEST);
	// �o�b�N�o�b�t�@�̓��e���t�����g�o�b�t�@�ɓ]��
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	// gult���C�u�����̏�����
	glutInit(&argc, argv);
	// ����������
	myInit(argv[0]);
	// ���C�g�̐ݒ�
	//mySetLight();
	// 
	glutReshapeFunc(myReshape);
	// �L�[�{�[�h�A�}�E�X���͂̃R�[���o�b�N�֐��Z�b�g
	glutKeyboardFunc(myKeyboard);
	//
	//glutMouseFunc(myMouseFunc);
	//glutMotionFunc(myMouseMotion);
	// �C�x���g���Ȃ��ꍇ�ɌĂ΂��֐����Z�b�g 
	glutIdleFunc(myIdle);
	// �`��p�֐�(�f�B�X�v���C�R�[���o�b�N�֐�)�Z�b�g
	glutDisplayFunc(myDisplay);

	// �C�x���g�������[�v
	glutMainLoop();

	return 0;
}