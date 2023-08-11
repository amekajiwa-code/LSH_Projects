#include "sample.h"

HRESULT MyDevice::CreateDevice() {
    HRESULT hResult = S_OK;

    D3D_DRIVER_TYPE DriverType = D3D_DRIVER_TYPE_HARDWARE;
    D3D_FEATURE_LEVEL FeatureLevels = D3D_FEATURE_LEVEL_11_0;
    UINT Flags = 0;

    hResult = D3D11CreateDevice(
        nullptr,
        DriverType,
        nullptr,
        Flags,
        &FeatureLevels,
        1,
        D3D11_SDK_VERSION,
        &mDevice,
        nullptr,
        &mImmediateContext
    );

    if (FAILED(hResult)) {
        return hResult;
    }

    return hResult;
}

HRESULT MyDevice::CreateFactory() {
    HRESULT hResult = S_OK;
    if (FAILED(hResult = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)(&mFactory)))) {
        return hResult;
    }
    return hResult;
}

HRESULT MyDevice::CreateSwapChain() {
    HRESULT hResult = S_OK;
    if (mFactory == NULL) return S_FALSE;

    DXGI_SWAP_CHAIN_DESC SwapChainDesc = {};
    //ZeroMemory(&SwapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));
    SwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    SwapChainDesc.BufferCount = 1;
    SwapChainDesc.OutputWindow = mHWnd;
    SwapChainDesc.Windowed = true;
    SwapChainDesc.BufferDesc.Width = 800;
    SwapChainDesc.BufferDesc.Height = 600;
    SwapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
    SwapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
    SwapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    SwapChainDesc.SampleDesc.Count = 1;

    if (FAILED(hResult = mFactory->CreateSwapChain(mDevice, &SwapChainDesc, &mSwapChain))) {
        return hResult;
    }

    return hResult;
}

HRESULT MyDevice::SetRenderTargetView() {
    HRESULT hResult;
    ID3D11Texture2D* backBuffer;
    hResult = mSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer);

    if (SUCCEEDED(hResult)) {
        hResult = mDevice->CreateRenderTargetView(backBuffer, NULL, &mRenderTargetView);

        if (FAILED(hResult)) {
            backBuffer->Release();
            return hResult;
        }
    }
}

HRESULT MyDevice::SetViewPort() {
    HRESULT hResult = S_OK;
    mViewPort.Width = static_cast<float>(mDwWindowWidth);
    mViewPort.Height = static_cast<float>(mDwWindowHeight);
    mViewPort.MinDepth = 0.0f;
    mViewPort.MaxDepth = 1.0f;
    mViewPort.TopLeftX = 0;
    mViewPort.TopLeftY = 0;
    mImmediateContext->RSSetViewports(1, &mViewPort); // 레스터라이저
    return hResult;
}

HRESULT MyDevice::CreateVertexBuffer()
{
    HRESULT hResult = S_OK;
    mVertices.resize(6);
    mVertices[0].x = -1.0f; mVertices[0].y = 1.0f; mVertices[0].z = 0.5f;
    mVertices[1].x = 1.0f; mVertices[1].y = 1.0f; mVertices[1].z = 0.5f;
    mVertices[2].x = -1.0f; mVertices[2].y = -1.0f; mVertices[2].z = 0.5f;

    mVertices[3].x = -1.0f; mVertices[3].y = -1.0f; mVertices[3].z = 0.5f;
    mVertices[4].x = 1.0f; mVertices[4].y = 1.0f; mVertices[4].z = 0.5f;
    mVertices[5].x = 1.0f; mVertices[5].y = -1.0f; mVertices[5].z = 0.5f;

    return hResult;
}

HRESULT MyDevice::LoadShaderAndInputLayout()
{
    HRESULT hResult = S_OK;

    return hResult;
}

bool sample::Init() {
    CreateDevice();
    CreateFactory();
    CreateSwapChain();
    SetRenderTargetView();
    SetViewPort();
    return true;
};

bool sample::Frame() {
    return true; 
};

bool sample::Render() {
    float color[4] = { 1.0f , 0.5f, 0.5f, 1.0f };
    mImmediateContext->ClearRenderTargetView(mRenderTargetView, color);
    // 지형, 캐릭터, 오브젝트, 이펙트, 인터페이스
    HRESULT hResult = mSwapChain->Present(0, 0);

    if (FAILED(hResult)) return false;

    return true; 
};

bool sample::Release() {
    if (mSwapChain) mSwapChain->Release();
    if (mDevice) mDevice->Release();

    if (mImmediateContext) {
        mImmediateContext->ClearState();
        mImmediateContext->Release();
    }

    if (mRenderTargetView) mRenderTargetView->Release();
    if (mFactory) mFactory->Release();

    mFactory = nullptr;
    mDevice = nullptr;
    mImmediateContext = nullptr;
    mSwapChain = nullptr;
    mRenderTargetView = nullptr;

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