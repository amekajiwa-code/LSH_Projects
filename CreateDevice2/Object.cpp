#include "Object.h"
#include "DirectXTex.h"

void Object::Set(ID3D11Device* device, ID3D11DeviceContext* immediateContext)
{
    mDevice = device;
    mImmediateContext = immediateContext;
}

bool Object::Create(std::wstring texFileName)
{
    CreateVertexBuffer();
    LoadVertexShader();
    LoadPixelShader();
    InputLayout();
    LoadTextureFile(texFileName);
    
    return true;
}

bool Object::LoadTextureFile(std::wstring fileName)
{
    auto imageobj = std::make_unique<DirectX::ScratchImage>();
    DirectX::TexMetadata mdata;

    HRESULT hr = DirectX::GetMetadataFromDDSFile(fileName.c_str(), DirectX::DDS_FLAGS_NONE, mdata);
    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromWICFile(fileName.c_str(), DirectX::WIC_FLAGS_NONE, &mdata, *imageobj);
        if (SUCCEEDED(hr))
        {
            hr = DirectX::CreateShaderResourceView(mDevice, imageobj->GetImages(), imageobj->GetImageCount(), mdata, &mTexSRV);
            if (SUCCEEDED(hr))
            {
                return true;
            }
        }
    }
    hr = DirectX::GetMetadataFromWICFile(fileName.c_str(), DirectX::WIC_FLAGS_NONE, mdata);
    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromWICFile(fileName.c_str(), DirectX::WIC_FLAGS_NONE, &mdata, *imageobj);
        if (SUCCEEDED(hr))
        {
            hr = DirectX::CreateShaderResourceView(mDevice, imageobj->GetImages(), imageobj->GetImageCount(), mdata, &mTexSRV);
            if (SUCCEEDED(hr))
            {
                return true;
            }
        }
    }
    hr = DirectX::GetMetadataFromTGAFile(fileName.c_str(), DirectX::TGA_FLAGS_NONE, mdata);
    if (SUCCEEDED(hr))
    {
        hr = DirectX::LoadFromTGAFile(fileName.c_str(), DirectX::TGA_FLAGS_NONE, &mdata, *imageobj);
        if (SUCCEEDED(hr))
        {
            hr = DirectX::CreateShaderResourceView(mDevice, imageobj->GetImages(), imageobj->GetImageCount(), mdata, &mTexSRV);
            if (SUCCEEDED(hr))
            {
                return true;
            }
        }
    }
    return false;
}

HRESULT Object::CreateVertexBuffer()
{
    //좌표계 기준으로 왼쪽위에 삼각형 형성
    verticles.resize(6);
    // u, v
    verticles[0].u = 0.0f; verticles[0].v = 0.0f;
    verticles[1].u = 1.0f; verticles[1].v = 0.0f;
    verticles[2].u = 0.0f; verticles[2].v = 1.0f;
    verticles[3].u = 0.0f; verticles[3].v = 1.0f;
    verticles[4].u = 1.0f; verticles[4].v = 0.0f;
    verticles[5].u = 1.0f; verticles[5].v = 1.0f;
    // x, y, z
    verticles[0].x = -1.0f; verticles[0].y = 1.0f; verticles[0].z = 0.0f;
    verticles[1].x = 1.0f; verticles[1].y = 1.0f; verticles[1].z = 0.0f;
    verticles[2].x = -1.0f; verticles[2].y = -1.0f; verticles[2].z = 0.0f;
    verticles[3].x = -1.0f; verticles[3].y = -1.0f; verticles[3].z = 0.0f;
    verticles[4].x = 1.0f; verticles[4].y = 1.0f; verticles[4].z = 0.0f;
    verticles[5].x = 1.0f; verticles[5].y = -1.0f; verticles[5].z = 0.0f;

    D3D11_BUFFER_DESC bufferDesc = {};
    bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    bufferDesc.ByteWidth = sizeof(P3VERTEX) * verticles.size();
    bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA InitData = {};
    InitData.pSysMem = &verticles.at(0);

    HRESULT hResult = mDevice->CreateBuffer(&bufferDesc, &InitData, &mVertexBuffer);
    if (FAILED(hResult))
    {
        return hResult;
    }

    return hResult;
}

HRESULT Object::LoadVertexShader()
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

HRESULT Object::LoadPixelShader()
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

HRESULT Object::InputLayout()
{
    const D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "TEXTURE",  0, DXGI_FORMAT_R32G32_FLOAT, 0, 12,  D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };

    UINT numCount = sizeof(layout) / sizeof(layout[0]);
    HRESULT hResult = mDevice->CreateInputLayout(
        layout,
        numCount,
        mVertexShaderCode->GetBufferPointer(),
        mVertexShaderCode->GetBufferSize(),
        &mVertexLayout);

    if (FAILED(hResult)) {
        return hResult;
    }

    return hResult;
}

bool Object::Init()
{
    return true;
}

bool Object::Frame()
{
    return true;
}

bool Object::Render()
{
    mImmediateContext->PSSetShaderResources(0, 1, &mTexSRV);

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

bool Object::Release()
{
    if (mVertexBuffer) mVertexBuffer->Release();
    if (mVertexLayout) mVertexLayout->Release();
    if (mVS) mVS->Release();
    if (mPS) mPS->Release();
    return true;
}