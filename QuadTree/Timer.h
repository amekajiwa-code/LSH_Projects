#pragma once
#include <windows.h>
#pragma comment (lib, "Winmm.lib")

class Timer
{
public:
	// �� �����Ӵ� �ɸ��� �ð�
	float mSecondPerFrame;
	// ���ݱ��� �帥 �ð� ����
	float mTimer;
	// ���� �������� �ð�
	DWORD mBeforeTime;
private:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};

