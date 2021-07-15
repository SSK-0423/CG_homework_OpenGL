#pragma once
#include <time.h>
#include <Windows.h>
class FPS {
private:
	//計測開始時刻
	time_t startTime;
	//フレーム数
	int frameCount;
	static const int sampleNum = 60;
	// 実際のFPS値
	static float measFPS;
	// 設定したFPS値
	static int setFPS;

public:
	FPS();
	~FPS();
	void Update();
	//待機
	void Wait();
	//FPS設定
	void SetFPS(const int& fps);
	//計測したFPS値取得
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
		//計測開始時刻
		startTime = clock();
	}
	if (frameCount == sampleNum) {
		//60フレーム経過後の時刻
		time_t time = clock();
		//fpsの平均値計算
		//1000ms(1秒) / (サンプル数分のフレームにかかった時間 / サンプル数)
		measFPS = 1000.f / ((time - startTime) / (float)sampleNum);
		frameCount = 0;
		startTime = time;
	}
	frameCount++;
}

void FPS::Wait() {
	//実際にかかった時間
	int tookTime = clock() - startTime;
	//待つべき時間
	int waitTime = frameCount * 1000.f / setFPS - tookTime;
	//待つ
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
