#pragma once
#include <time.h>
#include <Windows.h>
class FPS {
private:
	//�v���J�n����
	time_t startTime;
	//�t���[����
	int frameCount;
	static const int sampleNum = 60;
	// ���ۂ�FPS�l
	static float measFPS;
	// �ݒ肵��FPS�l
	static int setFPS;

public:
	FPS();
	~FPS();
	void Update();
	//�ҋ@
	void Wait();
	//FPS�ݒ�
	void SetFPS(const int& fps);
	//�v������FPS�l�擾
	float GetFPS();
};

float FPS::measFPS;
int FPS::setFPS;

FPS::FPS() {
	startTime = 0;
	frameCount = 0;
	measFPS = 0;
	setFPS = 60;
}

FPS::~FPS() {
}

void FPS::Update() {
	if (frameCount == 0) {
		//�v���J�n����
		startTime = clock();
	}
	if (frameCount == sampleNum) {
		//60�t���[���o�ߌ�̎���
		time_t time = clock();
		//fps�̕��ϒl�v�Z
		//1000ms(1�b) / (�T���v�������̃t���[���ɂ����������� / �T���v����)
		measFPS = 1000.f / ((time - startTime) / (float)sampleNum);
		frameCount = 0;
		startTime = time;
	}
	frameCount++;
}

void FPS::Wait() {
	//���ۂɂ�����������
	int tookTime = clock() - startTime;
	//�҂ׂ�����
	int waitTime = frameCount * 1000.f / setFPS - tookTime;
	//�҂�
	if (waitTime > 0) {
		Sleep(waitTime);
	}
}

void FPS::SetFPS(const int& fps) {
	setFPS = fps;
}
float FPS::GetFPS() {
	return measFPS;
}
