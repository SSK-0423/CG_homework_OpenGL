#pragma once
#include "Vector3D.h"
#include "GL/glut.h"

//ゲームで使用する構造体
template<class ...T>
struct Size3D;

template<>
struct Size3D<int> {
	int width;
	int height;
	int depth;
};

template<>
struct Size3D<float> {
	float width;
	float height;
	float depth;
};

template<>
struct Size3D<double> {
	double width;
	double height;
	double depth;
};

template <class ...T>
struct Position3D;
/* 以下特殊化 */
template<>
struct Position3D<int> {
	int x;
	int y;
	int z;
};

template<>
struct Position3D<float> {
	float x;
	float y;
	float z;
};

template<>
struct Position3D<double> {
	double x;
	double y;
	double z;
};

template<class ...T>
struct RotateAngle3D;

/* 以下特殊化 */
template<>
struct RotateAngle3D<int> {
	int x;
	int y;
	int z;
};

template<>
struct RotateAngle3D<float> {
	float x;
	float y;
	float z;
};

template<>
struct RotateAngle3D<double> {
	double x;
	double y;
	double z;
};

// マテリアルのパラメータ構造体
typedef struct MaterialParam {
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
	GLfloat emission[4];
	GLfloat shininess;
};

//  色
typedef unsigned int Color;
//  画像
typedef int Image;
//  オーディオ
typedef int Audio;

