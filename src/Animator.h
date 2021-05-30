#pragma once
// アニメータ－クラス
template<class ...T>
class Animator {
public:
	virtual void Animation(T... t) = 0;
};
