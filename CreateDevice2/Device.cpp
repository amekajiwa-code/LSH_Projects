#include "Device.h"

bool Device::Init() {
    // ����ü�� �Ӽ��� ����ü: ������۸��� �����ϴµ� ����
    DXGI_SWAP_CHAIN_DESC SwapChainDesc; // ����ü�� �Ӽ��� ����ü: ������۸��� �����ϴµ� ����
    ZeroMemory(&SwapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
    SwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // ���� Ÿ��
    SwapChainDesc.BufferCount = 1;
    SwapChainDesc.OutputWindow = mHWnd;
    SwapChainDesc.Windowed = true;
    //�� ���� ����
    SwapChainDesc.BufferDesc.Width = mDwWindowWidth; // ���� ũ��
    SwapChainDesc.BufferDesc.Height = mDwWindowHeight;
    SwapChainDesc.BufferDesc.RefreshRate.Numerator = 60; // ���� �ֻ��� ����
    SwapChainDesc.BufferDesc.RefreshRate.Denominator = 1; // ���� �ֻ��� �и�
    SwapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // �� ����
    //�� ���� ��Ƽ���ø� count
    SwapChainDesc.SampleDesc.Count = 1;

    D3D_DRIVER_TYPE DriverType = D3D_DRIVER_TYPE_HARDWARE;
    UINT Flags = 0;
    D3D_FEATURE_LEVEL FeatureLevels = D3D_FEATURE_LEVEL_11_0; // �ּ� ���� DX11

    //1) ����̽� ����
    HRESULT hResult = D3D11CreateDeviceAndSwapChain(
        NULL,
        DriverType,
        NULL,
        Flags,
        &FeatureLevels,
        1,
        D3D11_SDK_VERSION,
        &SwapChainDesc,
        &mSwapChain, // ����� �������̽�
        &mDevice, // dx �������̽� (����)
        NULL,
        &mImmediateContext // dx �������̽� (����)
    );

    if (FAILED(hResult)) return false;

    //2) ����� ������
    ID3D11Texture2D* backBuffer; // ����� ������
    hResult = mSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D)/*�������̽� ����*/, (LPVOID*)&backBuffer);//����ü���� ����� ������

    if (SUCCEEDED(hResult)) {
        //3) ����Ÿ�� ����
        hResult = mDevice->CreateRenderTargetView(backBuffer, NULL, &mRenderTargetView);

        if (FAILED(hResult)) {
            backBuffer->Release();
            return false;
        }
        mImmediateContext->OMSetRenderTargets(1, &mRenderTargetView, NULL);
    }
    backBuffer->Release();

    //����Ʈ ����
    mViewPort.Width = static_cast<float>(mDwWindowWidth);
    mViewPort.Height = static_cast<float>(mDwWindowHeight);
    mViewPort.MinDepth = 0.0f;
    mViewPort.MaxDepth = 1.0f;
    mViewPort.TopLeftX = 0;
    mViewPort.TopLeftY = 0;
    mImmediateContext->RSSetViewports(1, &mViewPort); // �����Ͷ�����

    return true;
};

bool Device::Frame() {
    return true;
};

bool  Device::PreRender()
{
    float color[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
    mImmediateContext->ClearRenderTargetView(mRenderTargetView, color);
    return true;
}
bool  Device::PostRender()
{
    HRESULT hr = mSwapChain->Present(0, 0);
    if (FAILED(hr))
    {
        return false;
    }
    return true;
}

bool Device::Render() {
    PreRender();
    PostRender();
    return true;
};

bool Device::Release() {
    if (mSwapChain) mSwapChain->Release();
    if (mDevice) mDevice->Release();
    if (mImmediateContext) mImmediateContext->Release();
    if (mRenderTargetView) mRenderTargetView->Release();
    return true;
};