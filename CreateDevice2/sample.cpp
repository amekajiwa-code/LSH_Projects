#include "sample.h"

//������: �Ȱ��� ���ҽ��� ��� �ݺ��ؼ� �ҷ����� ������ ��ȿ����
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

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) // ����
{
    sample mySample;
    mySample.SetRegisterWindow(hInstance);
    mySample.SetWindow(L"�ƹ��ų�", 800, 600);
    mySample.Run();

    return 0;
}