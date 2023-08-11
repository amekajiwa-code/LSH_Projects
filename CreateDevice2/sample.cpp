#include "sample.h"

HRESULT sample::CreateVertexBuffer()
{
    //좌표계 기준으로 왼쪽위에 삼각형 형성
    verticles.resize(9);
    verticles[0].x = -1.0f; verticles[0].y = 1.0f; verticles[0].z = 0.0f;
    verticles[1].x = 1.0f; verticles[1].y = 1.0f; verticles[1].z = 0.0f;
    verticles[2].x = -1.0f; verticles[2].y = 0.0f; verticles[2].z = 0.0f;

    verticles[3].x = -1.0f; verticles[3].y = -1.0f; verticles[3].z = 0.0f;
    verticles[4].x = 1.0f; verticles[4].y = 0.0f; verticles[4].z = 0.0f;
    verticles[5].x = 1.0f; verticles[5].y = -1.0f; verticles[5].z = 0.0f;

    verticles[6].x = 0.0f; verticles[6].y = 0.5f; verticles[6].z = 0.0f;
    verticles[7].x = 0.5f; verticles[7].y = -0.5f; verticles[7].z = 0.0f;
    verticles[8].x = -0.5f; verticles[8].y = -0.5f; verticles[8].z = 0.0f;

    D3D11_BUFFER_DESC bufferDesc = {};
    bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    bufferDesc.ByteWidth = sizeof(P3VERTEX) * verticles.size();
    bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA InitData = {};
    InitData.pSysMem = &verticles.at(0);

    HRESULT hResult = mDevice->CreateBuffer(&bufferDesc, &InitData, &mVertexBuffer);
    if (FAILED(hResult))
    {
        MessageBoxA(mHWnd, "CreateVertexBuffer", "CreateVertexBuffer", MB_OK);
        return hResult;
    }

    return hResult;
}

HRESULT sample::LoadVertexShader()
{
    ID3DBlob* ErrorCode;
    // 버텍스 쉐이더 컴파일
    HRESULT hResult = D3DCompileFromFile(
        L"VertexShader.vsh",
        nullptr,
        nullptr,
        "VS",
        "vs_5_0",
        0,
        0,
        &mVertexShaderCode,
        &ErrorCode);
    if (FAILED(hResult))
    {
        MessageBoxA(mHWnd, "LoadVertexShader", "LoadVertexShader", MB_OK);
        return hResult;
    }
    hResult = mDevice->CreateVertexShader(
        mVertexShaderCode->GetBufferPointer(),
        mVertexShaderCode->GetBufferSize(),
        nullptr,
        &mVS);

    if (ErrorCode) ErrorCode->Release();
    return hResult;
}

HRESULT sample::LoadPixelShader()
{
    ID3DBlob* ShaderCode;
    ID3DBlob* ErrorCode;
    // 픽셀 쉐이더 컴파일
    HRESULT hResult = D3DCompileFromFile(
        L"PixelShader.psh",
        nullptr,
        nullptr,
        "PS",
        "ps_5_0",
        0,
        0,
        &ShaderCode,
        &ErrorCode);
    if (FAILED(hResult))
    {
        MessageBoxA(mHWnd, "LoadPixelShader", "LoadPixelShader", MB_OK);
        return hResult;
    }
    hResult = mDevice->CreatePixelShader(
        ShaderCode->GetBufferPointer(),
        ShaderCode->GetBufferSize(),
        nullptr,
        &mPS);

    if (ShaderCode) ShaderCode->Release();
    if (ErrorCode) ErrorCode->Release();
    return hResult;
}

HRESULT sample::InputLayout()
{
    const D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };

    UINT numCount = sizeof(layout) / sizeof(layout[0]);
    HRESULT hResult = mDevice->CreateInputLayout(
        layout,
        numCount,
        mVertexShaderCode->GetBufferPointer(),
        mVertexShaderCode->GetBufferSize(),
        &mVertexLayout);

    if (FAILED(hResult)) {
        MessageBoxA(mHWnd, "InputLayout", "InputLayout", MB_OK);
        return hResult;
    }

    return hResult;
}

bool sample::Init()
{
    CreateVertexBuffer();
    LoadVertexShader();
    LoadPixelShader();
    InputLayout();
    return true;
}

bool sample::Frame()
{
    return true;
}

bool sample::Render()
{
    mImmediateContext->IASetInputLayout(mVertexLayout);
    mImmediateContext->VSSetShader(mVS, NULL, 0);
    mImmediateContext->PSSetShader(mPS, NULL, 0);
    UINT stride = sizeof(P3VERTEX);
    UINT offset = 0;
    mImmediateContext->IASetVertexBuffers(0, 1, &mVertexBuffer, &stride, &offset);
    mImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    mImmediateContext->Draw(verticles.size(), 0);
    return true;
}

bool sample::Release()
{
    if (mVertexBuffer) mVertexBuffer->Release();
    if (mVertexLayout) mVertexLayout->Release();
    if (mVS) mVS->Release();
    if (mPS) mPS->Release();
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