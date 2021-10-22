#pragma once
// �A�j���[�^�|�N���X
template<class ...T>
class Animator {
protected:
	int frameCount;
public:
	virtual void Animation(T... t) = 0;
	void StopAnime() {
		frameCount = 0;
	}
};
