#pragma once
// �A�j���[�^�|�N���X
template<class ...T>
class Animator {
public:
	virtual void Animation(T... t) = 0;
};
