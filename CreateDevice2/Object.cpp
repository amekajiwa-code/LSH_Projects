#include "Object.h"

void Object::Set(ID3D11Device* device, ID3D11DeviceContext* immediateContext)
{
    mDevice = device;
    mImmediateContext = immediateContext;
}

bool Object::Create(TextureManager& texMg, wstring texFileName, ShaderManager& shaMg, wstring shaFileName)
{
    CreateVertexBuffer();
    mTexture = texMg.Load(texFileName);
    mShader = shaMg.Load(shaFileName);
    //LoadVertexShader();
    //LoadPixelShader();
    InputLayout();
    //LoadTextureFile(texFileName);
    
    return true;
}

bool Object::CreateVertexBuffer()
{
    //ÁÂÇ¥°è ±âÁØÀ¸·Î ¿ŞÂÊÀ§¿¡ »ï°¢Çü Çü¼º
    verticles.resize(6);
    // u, v
    verticles[0].u = 0.0f; verticles[0].v = 0.0f;
    verticles[1].u = 1.0f; verticles[1].v = 0.0f;
    verticles[2].u = 0.0f; verticles[2].v = 1.0f;
    verticles[3].u = 0.0f; verticles[3].v = 1.0f;
    verticles[4].u = 1.0f; verticles[4].v = 0.0f;
    verticles[5].u = 1.0f; verticles[5].v = 1.0f;
    // x, y, z
    verticles[0].x = -1.0f / 2; verticles[0].y = 1.0f / 2; verticles[0].z = 1.0f;
    verticles[1].x = 1.0f / 2; verticles[1].y = 1.0f / 2; verticles[1].z = 1.0f;
    verticles[2].x = -1.0f / 2; verticles[2].y = -1.0f / 2; verticles[2].z = 1.0f;
    verticles[3].x = -1.0f / 2; verticles[3].y = -1.0f / 2; verticles[3].z = 1.0f;
    verticles[4].x = 1.0f / 2; verticles[4].y = 1.0f / 2; verticles[4].z = 1.0f;
    verticles[5].x = 1.0f / 2; verticles[5].y = -1.0f / 2; verticles[5].z = 1.0f;

    D3D11_BUFFER_DESC bufferDesc = {};
    bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    bufferDesc.ByteWidth = sizeof(P3VERTEX) * verticles.size();
    bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

    D3D11_SUBRESOURCE_DATA InitData = {};
    InitData.pSysMem = &verticles.at(0);

    HRESULT hResult = mDevice->CreateBuffer(&bufferDesc, &InitData, &mVertexBuffer);
    if (FAILED(hResult))
    {
        return false;
    }

    return true;
}

bool Object::InputLayout()
{
    const D3D11_INPUT_ELEMENT_DESC layout[] =
    {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "TEXTURE",  0, DXGI_FORMAT_R32G32_FLOAT, 0, 12,  D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };

    UINT numCount = sizeof(layout) / sizeof(layout[0]);

    if (mShader) {
        HRESULT hResult = mDevice->CreateInputLayout(
            layout,
            numCount,
            mShader->GetBufferPointer(),
            mShader->GetBufferSize(),
            &mVertexLayout);

        if (FAILED(hResult)) {
            return false;
        }
    }
  
    return true;
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
    ID3D11ShaderResourceView* texSRV = nullptr;

    if (mTexture)
    {
        mTexture->Apply(mImmediateContext, 0);
    }

    mImmediateContext->IASetInputLayout(mVertexLayout);

    if (mShader)
    {
        mShader->Apply(mImmediateContext, 0);
    }

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

    return true;
}