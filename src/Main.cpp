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
#include "Player.h"
#include "GameData.h"
#include "Building.h"
#include <vector>

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

static std::vector<Spyder*> spyders;
static Stage stage;
static GameObject player;
static GameObject playerModel;
static FPS fps;
static Transform* pTransform;
static GameObject* obj;
static GameObject* obj2;

unsigned char	mouseFlag = GL_FALSE;		// flag for moving or not
int				xStart, yStart;				// start position when drug begins
double			xAngle = 0.0, yAngle = 0.0;	// angles of the teapot
static Position3D<float> playerPos;
float initMtr[4] = { 1.0,1.0,1.0,1.0 };
float moveSpeed = 0.3;
int animeStopCount = 0;


static MaterialParam sun = {
	{0.8,0.8,0.0,1.0},
	{0.8,0.8,0.0,1.0},
	{0.0,0.0,0.0,1.0},
	{0.8,0.8,0.0,1.0},
	128
};

static GLdouble normal[3] = { 0.0,1.0,0.0 };

// 初期化処理をまとめた関数
void myInit(char* progname)
{
	// ディスプレイモードの宣言
	// GLUT_DOUBLE ダブルバッファの使用を宣言
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	// ウィンドウサイズ指定
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	// ウィンドウの左上位置の指定
	glutInitWindowPosition(0, 0);
	// ウィンドウ生成 progname = ウィンドウネーム
	glutCreateWindow(progname);
	glShadeModel(GL_SMOOTH);
	// 初期色(?)
	//glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearColor(0.0, 0.85, 1.0, 1.0);
}

//描画関数
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glPushMatrix();
	{
		glPushMatrix();
		{
			glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, initMtr);
			player.GetComponent<Transform>()->SetRotateAngle(0, yAngle, 0);
			player.Draw();
			//playerModel.Draw();
			glMaterialfv(GL_FRONT, GL_AMBIENT, initMtr);
			for (auto obj : spyders) {
				obj->Draw();
				obj->Animation();
			}
			glMaterialfv(GL_FRONT, GL_AMBIENT, initMtr);
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
	glDisable(GL_LIGHTING);
	glDisable(GL_NORMALIZE);
	// バックバッファの内容をフロントバッファに転送
	glutSwapBuffers();

	if (animeStopCount <= 0) {
		player.GetComponent<Player>()->StopAnime();
	}
	else animeStopCount--;
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
	gluPerspective(90.0, (double)width / (double)height, 0.1, 150.0);
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
		player.GetComponent<Player>()->MoveForward(moveSpeed);
		animeStopCount = 10;
		glutPostRedisplay();
		break;
	case 'W':
		player.GetComponent<Player>()->MoveForward(moveSpeed);
		animeStopCount = 10;
		glutPostRedisplay();
		break;
	case 's':
		player.GetComponent<Player>()->MoveForward(-moveSpeed);
		animeStopCount = 10;
		glutPostRedisplay();
		break;
	case 'S':
		player.GetComponent<Player>()->MoveForward(-moveSpeed);
		animeStopCount = 10;
		glutPostRedisplay();
		break;
		//case 'd':
		//	glutPostRedisplay();
		//	break;
		//case 'D':
		//	glutPostRedisplay();
		//	break;
		//case 'a':
		//	playerModel.GetComponent<Player>()->animeState += 1;
		//	playerModel.GetComponent<Player>()->DrawAnimeState();
		//	glutPostRedisplay();
		//	break;
		//case 'A':
		//	playerModel.GetComponent<Player>()->animeState += 1;
		//	glutPostRedisplay();
		//	break;
		//case 'e':
		//	player.GetComponent<Player>()->MoveUP(0.5);
		//	glutPostRedisplay();
		//	break;
		//case 'E':
		//	player.GetComponent<Player>()->MoveUP(0.5);
		//	glutPostRedisplay();
		//	break;
		//case 'q':
		//	player.GetComponent<Player>()->MoveUP(-0.5);
		//	glutPostRedisplay();
		//	break;
		//case 'Q':
		//	player.GetComponent<Player>()->MoveUP(-0.5);
		//	glutPostRedisplay();
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
	fps.Update();
	glutPostRedisplay();
	fps.Wait();
}

void myMouseMotion(int x, int y)
{
	int		xdis, ydis;
	double	a = 0.5;

	//if (mouseFlag == GL_FALSE) return;
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
	//if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
	xStart = x;
	yStart = y;
	mouseFlag = GL_TRUE;
	//}
	//else {
	mouseFlag = GL_FALSE;
	//}
}

void mySetLight()
{
	/* LIGHT0:太陽光 */
	float light0_position[] = { 0,  100.0, 0, 0 };
	float light0_ambient[] = { 0.4, 0.4, 0.4, 0 };
	float light0_diffuse[] = { 0.5,0.5,0.5,0 };
	float light0_emission[] = { 1.0,1.0,1.0,0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0,GL_EMISSION,light0_emission);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, light0_ambient);

	float light1_position[] = { 0, 50.0, 0.0, 1.0 };	// point light source
	float light1_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	float light1_diffuse[] = { 0.0, 0.0, 0.0, 1.0 };
	float light1_specular[] = { 0.0, 0.0, 0.0, 1.0 };
	float light1_emission[] = { 0.0,1.0,0.0,1.0 };

	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
	//glLightfv(GL_LIGHT1, GL_EMISSION, light1_emission);

	glEnable(GL_LIGHT0);		// enable the 0th light
	glEnable(GL_LIGHT1);		// enable the 1st light
}

void InitTexture()
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	/* automatic mapping */
	glTexGenf(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenf(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
}

void Menu(int value) {
	switch (value)
	{
	case 1:
		printf("value:%d\n", value);
		player.GetComponent<Player>()->ChangeCamera(CAMERA_TPS);
		break;
	case 2:
		printf("value:%d\n", value);
		player.GetComponent<Player>()->ChangeCamera(CAMERA_FPS);
		break;
	case 3:
		printf("value:%d\n", value);
		for (auto obj : spyders) {
			delete obj;
		}
		spyders.clear();
		exit(0);
		break;
	default:
		break;
	}
}

void mySetMenu()
{
	glutCreateMenu(Menu);
	glutAddMenuEntry("TPS", 1);
	glutAddMenuEntry("FPS", 2);
	glutAddMenuEntry("GameEnd", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv)
{
	// gultライブラリの初期化
	glutInit(&argc, argv);
	// 初期化処理
	myInit(argv[0]);
	// ライトの設定
	mySetLight();
	// テクスチャマッピングの初期設定
	InitTexture();
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
	mySetMenu();
	player.AddComponent<Player>(true);
	pTransform = player.GetComponent<Transform>();
	playerPos = pTransform->GetPosition();
	playerModel.AddComponent<Player>(false);
	fps.SetFPS(60);
	for (int i = 0; i < 4; i++) {
		spyders.push_back(new Spyder(i));
	}
	// イベント処理ループ
	glutMainLoop();

	return 0;
}
