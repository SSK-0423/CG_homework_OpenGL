#pragma once
#include "Vector3D.h"
#include "GL/glut.h"

//�Q�[���Ŏg�p����\����
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
/* �ȉ����ꉻ */
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

/* �ȉ����ꉻ */
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

// �}�e���A���̃p�����[�^�\����
typedef struct MaterialParam {
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
	GLfloat emission[4];
	GLfloat shininess;
};

//  �F
typedef unsigned int Color;
//  �摜
typedef int Image;
//  �I�[�f�B�I
typedef int Audio;

