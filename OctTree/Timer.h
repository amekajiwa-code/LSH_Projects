#pragma once
#include <windows.h>
#pragma comment (lib, "Winmm.lib")

class Timer
{
public:
	float mSecondPerFrame;
	float mTimer;
	DWORD mBeforeTime;
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};

