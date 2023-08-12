#include "sample.h"

//문제점: 똑같은 리소스를 계속 반복해서 불러오기 때문에 비효율적
bool sample::Init()
{
    std::wstring texname = L"ana.jpg";
    obj = new Object;
    obj->Set(mDevice, mImmediateContext);
    obj->Create(texname);
    return true;
}

bool sample::Frame()
{
    obj->Frame();
    return true;
}

bool sample::Render()
{
    obj->Render();
    return true;
}

bool sample::Release()
{
    obj->Release();
    delete obj;
    return true;
}

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) // 메인
{
    sample mySample;
    mySample.SetRegisterWindow(hInstance);
    mySample.SetWindow(L"아무거나", 800, 600);
    mySample.Run();

    return 0;
}