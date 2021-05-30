
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

// 初期化処理をまとめた関数
void myInit(char* progname)
{
	// ディスプレイモードの宣言
	// GLUT_DOUBLE ダブルバッファの使用を宣言
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	// ウィンドウサイズ指定
	glutInitWindowSize(500, 500);
	// ウィンドウの左上位置の指定
	glutInitWindowPosition(0, 0);
	// ウィンドウ生成 progname = ウィンドウネーム
	glutCreateWindow(progname);
	// 初期色(?)
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

//描画関数
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
	
	// バックバッファの内容をフロントバッファに転送
	glutSwapBuffers();
}

// 
void myReshape(int width, int height)
{
	glViewport(0, 0, width, height);
	// 投影変換行列スタック
	glMatrixMode(GL_PROJECTION);
	// スタックの最上位に単位行列を格納
	glLoadIdentity();
	// 透視投影の設定(視野角、縦横比、前方クリップ面(z)、後方クリップ面(z) )
	// スタックの最上位にこの行列を格納
	gluPerspective(90.0, (double)width / (double)height, 0.1, 100.0);
	// モデル変換行列スタック
	glMatrixMode(GL_MODELVIEW);
	// スタックの最上位に単位行列を格納
	glLoadIdentity();
}

// キー入力関数
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

// イベントがない場合に呼ばれる関数
void myIdle(void)
{
	// ディスプレコールバック関数を呼ぶ
	// このプログラムの場合はmyDisplay
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
	// gultライブラリの初期化
	glutInit(&argc, argv);
	// 初期化処理
	myInit(argv[0]);
	// 
	glutReshapeFunc(myReshape);
	// キーボード、マウス入力のコールバック関数セット
	glutKeyboardFunc(myKeyboard);
	//
	glutMouseFunc(myMouseFunc);
	glutMotionFunc(myMouseMotion);
	// イベントがない場合に呼ばれる関数をセット 
	glutIdleFunc(myIdle);
	// 描画用関数(ディスプレイコールバック関数)セット
	glutDisplayFunc(myDisplay);
	// イベント処理ループ
	glutMainLoop();

	return 0;
}
