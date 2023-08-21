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
<<<<<<< HEAD
<<<<<<< HEAD
    CreateConstantBuffer();
    mTexture = texMg.Load(texFileName);
    mShader = shaMg.Load(shaFileName);
    //LoadVertexShader();
    //LoadPixelShader();
=======
    LoadVertexShader();
    LoadPixelShader();
>>>>>>> parent of 1a1c732 (ë¸”ë Œë”©)
=======
    LoadVertexShader();
    LoadPixelShader();
>>>>>>> parent of 1a1c732 (ë¸”ë Œë”©)
    InputLayout();
    LoadTextureFile(texFileName);
    
    return true;
}

<<<<<<< HEAD
<<<<<<< HEAD
void Object::SetPos(Vector3 pos)
=======
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
>>>>>>> parent of 1a1c732 (ë¸”ë Œë”©)
{
    mPos = pos;
}

void Object::SetScale(Vector3 scale)
{
    mScale = scale;
}

void Object::SetMatrix(Matrix* matWorld, Matrix* matView, Matrix* matProjection)
{
    if (matWorld != nullptr)
    {
        mMatWorld = *matWorld;
        mMatData.matWorld = mMatWorld.Transpose();
    }
    
    if (matView != nullptr)
    {
        mMatView = *matView;
        mMatData.matView = mMatView.Transpose();
    }

    if (matProjection != nullptr)
    {
        mMatProjection = *matProjection;
        mMatData.matProjection = mMatProjection.Transpose();
    }
    
    mMatData.matWorld = mMatWorld.Transpose();
    mMatData.matView = mMatView.Transpose();
    mMatData.matProjection = mMatProjection.Transpose();
    mImmediateContext->UpdateSubresource(mConstantBuffer, 0, nullptr, &mMatData, 0, 0);
}

bool Object::CreateConstantBuffer()
{
    D3D11_BUFFER_DESC bufferDesc = {};
    bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    bufferDesc.ByteWidth = sizeof(MatrixData);
    bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

    HRESULT hResult = mDevice->CreateBuffer(&bufferDesc, nullptr, &mConstantBuffer);
    if (FAILED(hResult))
    {
        return false;
    }

    return true;
}

bool Object::CreateVertexBuffer()
=======
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
>>>>>>> parent of 1a1c732 (ë¸”ë Œë”©)
{
    return true;

    //ÁÂÇ¥°è ±âÁØÀ¸·Î ¿ÞÂÊÀ§¿¡ »ï°¢Çü Çü¼º
    verticles.resize(6);
    // u, v
    verticles[0].t.mX = 0.0f; verticles[0].t.mY = 0.0f;
    verticles[1].t.mX = 1.0f; verticles[1].t.mY = 0.0f;
    verticles[2].t.mX = 0.0f; verticles[2].t.mY = 1.0f;
    verticles[3].t.mX = 0.0f; verticles[3].t.mY = 1.0f;
    verticles[4].t.mX = 1.0f; verticles[4].t.mY = 0.0f;
    verticles[5].t.mX = 1.0f; verticles[5].t.mY = 1.0f;
    // x, y, z
<<<<<<< HEAD
<<<<<<< HEAD
    verticles[0].p.mX = -1.0f; verticles[0].p.mY = 1.0f; verticles[0].p.mZ = 1.0f;
    verticles[1].p.mX = 1.0f; verticles[1].p.mY = 1.0f; verticles[1].p.mZ = 1.0f;
    verticles[2].p.mX = -1.0f; verticles[2].p.mY = -1.0f; verticles[2].p.mZ = 1.0f;
    verticles[3].p.mX = -1.0f; verticles[3].p.mY = -1.0f; verticles[3].p.mZ = 1.0f;
    verticles[4].p.mX = 1.0f; verticles[4].p.mY = 1.0f; verticles[4].p.mZ = 1.0f;
    verticles[5].p.mX = 1.0f; verticles[5].p.mY = -1.0f; verticles[5].p.mZ = 1.0f;
=======
=======
>>>>>>> parent of 1a1c732 (ë¸”ë Œë”©)
    verticles[0].x = -1.0f; verticles[0].y = 1.0f; verticles[0].z = 0.0f;
    verticles[1].x = 1.0f; verticles[1].y = 1.0f; verticles[1].z = 0.0f;
    verticles[2].x = -1.0f; verticles[2].y = -1.0f; verticles[2].z = 0.0f;
    verticles[3].x = -1.0f; verticles[3].y = -1.0f; verticles[3].z = 0.0f;
    verticles[4].x = 1.0f; verticles[4].y = 1.0f; verticles[4].z = 0.0f;
    verticles[5].x = 1.0f; verticles[5].y = -1.0f; verticles[5].z = 0.0f;
<<<<<<< HEAD
>>>>>>> parent of 1a1c732 (ë¸”ë Œë”©)
=======
>>>>>>> parent of 1a1c732 (ë¸”ë Œë”©)

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
    // ¹öÅØ½º ½¦ÀÌ´õ ÄÄÆÄÀÏ
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
    // ÇÈ¼¿ ½¦ÀÌ´õ ÄÄÆÄÀÏ
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