#pragma once
#include "Vector3D.h"
#include "SpyderHead.h"
#include "SpyderLeg.h"
#include "SpyderTale.h"
#include "FrontLegAnimator.h"
#include "MiddleLegAnimator.h"

class Spyder {
private:
	//前脚のアニメータ
	static FrontLegAnimator frontLegAni;
	//後脚のアニメータ
	static MiddleLegAnimator middleLegAni;
	//座標
	Vector3D position;
	//6本脚
	SpyderLeg leg[8];
	//頭
	SpyderHead head;
	//尾
	SpyderTale tale;
	// アニメーションの設定
	void InitAnimation();
public:
	Spyder();
	//描画関数
	void Draw();
	// 移動
	void MovePosition(float x, float y, float z);
	// アニメーション
	void Animation();
};