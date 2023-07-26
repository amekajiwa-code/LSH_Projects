#include "Timer.h"

bool Timer::Init() {
	mSecondPerFrame = 0.0f;
	mTimer = 0.0f;
	//�ý����� ���õ� ������ ��� �ð��� �и��� ������ ��ȯ
	mBeforeTime = timeGetTime();
	
	return false;
}

bool Timer::Frame() {
	// ���� ���������� ���� ���������ӱ��� �󸶳� �ð��� �귶���� ����
	DWORD currentTime = timeGetTime();
	DWORD elapseTime = currentTime - mBeforeTime;
	// 1�ʴ� 1000�и����̹Ƿ� ������ �и��� ������ ����
	mSecondPerFrame = elapseTime / 1000.0f;
	// ���ݱ��� �帥 �ð� ����
	mTimer += mSecondPerFrame;
	//���������� �ð��� ���� �����ӽð����� ����
	mBeforeTime = currentTime;
	
	return false;
}

bool Timer::Render() {
	return 0;
}

bool Timer::Release() {
	return 0;
}