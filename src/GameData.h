#pragma once
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

//  色
typedef unsigned int Color;
//  画像
typedef int Image;
//  オーディオ
typedef int Audio;

