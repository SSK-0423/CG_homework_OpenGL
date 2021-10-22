#pragma once
#include <GL/glut.h>

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

class OpenGLInit{
private:
public:

};
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
	// 初期色(?)
	glClearColor(0.0, 0.0, 0.0, 0.0);
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

void myKeyboard(unsigned char key, int x, int y)
{

}

// イベントがない場合に呼ばれる関数
void myIdle(void)
{
	// ディスプレコールバック関数を呼ぶ
	// このプログラムの場合はmyDisplay
	glutPostRedisplay();
}

//描画関数
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_DEPTH_TEST);
	// バックバッファの内容をフロントバッファに転送
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	// gultライブラリの初期化
	glutInit(&argc, argv);
	// 初期化処理
	myInit(argv[0]);
	// ライトの設定
	//mySetLight();
	// 
	glutReshapeFunc(myReshape);
	// キーボード、マウス入力のコールバック関数セット
	glutKeyboardFunc(myKeyboard);
	//
	//glutMouseFunc(myMouseFunc);
	//glutMotionFunc(myMouseMotion);
	// イベントがない場合に呼ばれる関数をセット 
	glutIdleFunc(myIdle);
	// 描画用関数(ディスプレイコールバック関数)セット
	glutDisplayFunc(myDisplay);

	// イベント処理ループ
	glutMainLoop();

	return 0;
}