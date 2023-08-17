#include "Core.h"

bool  Core::Init() {	return true;}
bool  Core::Frame() {	return true;}
bool  Core::Render() {	return true;}
bool  Core::Release() {	return true;}

bool  Core::EngineInit() {
    Device::Init();
	Init();
	return true;
}

bool  Core::EngineFrame() {
    Device::Frame();
	Frame();
	return true;
}

bool  Core::EngineRender() {
    Device::PreRender();
	Render();
    Device::PostRender();
	return true;
}

bool  Core::EngineRelease() {
    Device::Release();
	Release();
	return true;
}

bool  Core::Run() // 윈도우 루프 동작
{
    EngineInit();
    MSG msg = { 0 };
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            // 게임로직을 처리
            if (!EngineFrame() || !EngineRender()) {
                break;
            }
        }
    }
    EngineRelease();
    return true;
}