#include "sample.h"

bool sample::Init() {
    DXGI_SWAP_CHAIN_DESC SwapChainDesc; // ����ü�� �Ӽ��� ����ü: ������۸��� �����ϴµ� ����
    ZeroMemory(&SwapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
    SwapChainDesc.BufferDesc.Width = 800; // ���� ũ��
    SwapChainDesc.BufferDesc.Height = 600;
    SwapChainDesc.BufferDesc.RefreshRate.Numerator = 60; // ���� �ֻ��� ����
    SwapChainDesc.BufferDesc.RefreshRate.Denominator = 1; // ���� �ֻ��� �и�
    SwapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // �� ����
    SwapChainDesc.SampleDesc.Count = 1; // �� ���� ��Ƽ���ø� count
    SwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // ���� Ÿ��
    SwapChainDesc.BufferCount = 1;
    SwapChainDesc.OutputWindow = mHWnd;
    SwapChainDesc.Windowed = true;

    D3D_DRIVER_TYPE DriverType = D3D_DRIVER_TYPE_HARDWARE;
    UINT Flags = 0;
    D3D_FEATURE_LEVEL FeatureLevels = D3D_FEATURE_LEVEL_11_0; // �ּ� ���� DX11

    //1) ����̽� ����
    HRESULT hResult = D3D11CreateDeviceAndSwapChain(NULL, DriverType, NULL, Flags, &FeatureLevels, 1, D3D11_SDK_VERSION,
        &SwapChainDesc,
        &mSwapChain, // ����� �������̽�
        &mDevice, // dx �������̽� (����)
        NULL,
        &mImmediateContext // dx �������̽� (����)
    );

    if (FAILED(hResult)) return false;

    //2) ����� ������
    ID3D11Texture2D* backBuffer; // ����� ������
    hResult = mSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D)/*�������̽� ����*/ , (LPVOID*)&backBuffer);//����ü���� ����� ������

    if (SUCCEEDED(hResult)) {
        //3) ����Ÿ�� ����
        hResult = mDevice->CreateRenderTargetView(backBuffer, NULL, &mRenderTargetView);

        if (FAILED(hResult)) {
            backBuffer->Release();
            return false;
        }
    }
    
    //4) �ÿ�
    backBuffer->Release();
    return true;
};

bool sample::Frame() {
    return true; 
};

bool sample::Render() {
    float color[4] = { 1.0f , 0, 0, 1.0f };
    mImmediateContext->ClearRenderTargetView(mRenderTargetView, color);
    // ����, ĳ����, ������Ʈ, ����Ʈ, �������̽�
    HRESULT hResult = mSwapChain->Present(0, 0);

    if (FAILED(hResult)) return false;

    return true; 
};

bool sample::Release() {
    if (mSwapChain) mSwapChain->Release();
    if (mDevice) mDevice->Release();
    if (mImmediateContext) mImmediateContext->Release();
    if (mRenderTargetView) mRenderTargetView->Release();
    return true; 
};

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) // ����
{
    sample mySample;
    mySample.SetRegisterWindow(hInstance);
    mySample.SetWindow(L"�ƹ��ų�", 800, 600);
    mySample.Run();

    return 0;
}