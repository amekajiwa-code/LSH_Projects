#pragma once
#include <windows.h>
#pragma comment (lib, "Winmm.lib")

class Timer
{
public:
	// 한 프레임당 걸리는 시간
	float mSecondPerFrame;
	// 지금까지 흐른 시간 축적
	float mTimer;
	// 이전 프레임의 시간
	DWORD mBeforeTime;
private:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};

