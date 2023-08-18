#include "Core.h"

bool  Core::Init() {	return true;}
bool  Core::Frame() {	return true;}
bool  Core::Render() {	return true;}
bool  Core::Release() {	return true;}

bool  Core::EngineInit() {
    Device::Init();
    mGameTimer.Init();
	Init();
	return true;
}

bool  Core::EngineFrame() {
    Device::Frame();
    mGameTimer.Frame();
	Frame();
	return true;
}

bool  Core::EngineRender() {
    Device::PreRender();
    mGameTimer.Render();
	Render();
    Device::PostRender();
	return true;
}

bool  Core::EngineRelease() {
    Device::Release();
    mGameTimer.Release();
	Release();
	return true;
}

bool  Core::Run() // ������ ���� ����
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
            // ���ӷ����� ó��
            if (!EngineFrame() || !EngineRender()) {
                break;
            }
        }
    }
    EngineRelease();
    return true;
}