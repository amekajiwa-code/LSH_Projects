#include "Timer.h"

bool Timer::Init() {
	mSecondPerFrame = 0.0f;
	mTimer = 0.0f;
	//시스템이 부팅된 이후의 경과 시간을 밀리초 단위로 반환
	mBeforeTime = timeGetTime();
	
	return false;
}

bool Timer::Frame() {
	// 그전 프레임으로 부터 현재프레임까지 얼마나 시간이 흘렀는지 저장
	DWORD currentTime = timeGetTime();
	DWORD elapseTime = currentTime - mBeforeTime;
	// 1초는 1000밀리초이므로 나눠서 밀리초 단위로 저장
	mSecondPerFrame = elapseTime / 1000.0f;
	// 지금까지 흐른 시간 누적
	mTimer += mSecondPerFrame;
	//현재프레임 시간을 이전 프레임시간으로 저장
	mBeforeTime = currentTime;
	
	return false;
}

bool Timer::Render() {
	return 0;
}

bool Timer::Release() {
	return 0;
}