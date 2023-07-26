#include "Timer.h"

bool Timer::Init() {
	mSecondPerFrame = 0.0f;
	mTimer = 0.0f;
	mBeforeTime = timeGetTime();
	return false;
}

bool Timer::Frame() {
	DWORD currentTime = timeGetTime();
	DWORD elapseTime = currentTime - mBeforeTime;
	mSecondPerFrame = elapseTime / 1000.0f;
	mTimer += mSecondPerFrame;
	mBeforeTime = currentTime;
	return false;
}

bool Timer::Render() {
	return 0;
}

bool Timer::Release() {
	return 0;
}
