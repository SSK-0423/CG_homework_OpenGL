#pragma once
#include "Vector3D.h"
#include "SpyderHead.h"
#include "SpyderLeg.h"
#include "SpyderTale.h"
#include "FrontLegAnimator.h"
#include "MiddleLegAnimator.h"
#include "HindLegAnimator.h"
#include <vector>

class Spyder {
private:
	int angle;
	int state;
	//前脚のアニメータ
	static FrontLegAnimator frontLegAni;
	//中央の脚のアニメータ
	static MiddleLegAnimator middleLegAni;
	//後ろ脚のアニメータ
	static HindLegAnimator hindLegAni;
	//6本脚
	SpyderLeg leg[8];
	//頭
	SpyderHead head;
	//尾
	SpyderTale tale;
	//移動用
	std::vector<int> z = { 0,-30, -30, 0,30,30,  30,  0, 0};
	std::vector<int> x = { 0,  0,  30,30,30, 0, -30,-30, 0};
	std::vector<float> xLerp;
	std::vector<float> zLerp;
	// アニメーションの設定
	void InitAnimation();
	// クモの移動アニメーション
	void MoveAnimation();
	void DebugDraw();
public:
	//座標
	Vector3D position;
	Spyder();
	//描画関数
	void Draw();
	// 移動
	void MovePosition(float x, float y, float z);
	// 回転
	void Rotate(int angle);
	// アニメーション
	void Animation();
	// 角度取得
	int GetAngle();
};