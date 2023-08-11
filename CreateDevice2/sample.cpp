#include "sample.h"

bool sample::Init() {
    return true;
};

bool sample::Frame() {
    return true; 
};

bool sample::Render() {
    return true; 
};

bool sample::Release() {
    return true; 
};

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) // 메인
{
    sample mySample;
    mySample.SetRegisterWindow(hInstance);
    mySample.SetWindow(L"아무거나", 800, 600);
    mySample.Run();

    return 0;
}