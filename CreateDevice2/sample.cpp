#include "sample.h"

//������: �Ȱ��� ���ҽ��� ��� �ݺ��ؼ� �ҷ����� ������ ��ȿ���� -> �Ŵ����� ���� �ؼ�
bool sample::Init()
{
    D3D11_BLEND_DESC blendDesc = {};
    blendDesc.RenderTarget[0].BlendEnable = true;
    blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_COLOR;
    blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_COLOR;
    blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
    blendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
    //blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_SRC_ALPHA;
    blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
    //blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_INV_SRC_ALPHA;
    blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
    blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

    mDevice->CreateBlendState(&blendDesc, &mAlphaBlend);
    mTexMg.Set(mDevice, mImmediateContext);
    mShaMg.Set(mDevice, mImmediateContext);

    std::wstring texname = L"anaalpha.png";
    obj = new Object;
    obj->Set(mDevice, mImmediateContext);
    obj->Create(mTexMg, texname, mShaMg, L"Plane.hlsl");
    return true;
}

bool sample::Frame()
{
    obj->Frame();
    return true;
}

bool sample::Render()
{
    mImmediateContext->OMSetBlendState(mAlphaBlend, 0, -1);
    obj->Render();
    return true;
}

bool sample::Release()
{
    obj->Release();
    delete obj;
    mAlphaBlend->Release();
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