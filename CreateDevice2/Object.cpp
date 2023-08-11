//#include "Object.h"
//
//HRESULT Object::CreateVertexBuffer() 
//{
//	verticles.resize(3);
//	verticles[0].x = 0.0f; verticles[0].y = 1.0f; verticles[0].z = 1.0f;
//	verticles[1].x = 1.0f; verticles[1].y = -1.0f; verticles[1].z = 1.0f;
//	verticles[2].x = -1.0f; verticles[2].y = -1.0f; verticles[2].z = 1.0f;
//
//	D3D11_BUFFER_DESC bufferDesc = {};
//	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
//	bufferDesc.ByteWidth = sizeof(P3VERTEX) * verticles.size();
//	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
//
//	D3D11_SUBRESOURCE_DATA InitData = {};
//	InitData.pSysMem = &verticles.at(0);
//
//	HRESULT hResult = mDevice->CreateBuffer(&bufferDesc, &InitData, &mVertexBuffer);
//	if (FAILED(hResult))
//	{
//		return hResult;
//	}
//
//	return hResult;
//}
//
//HRESULT Object::LoadVertexShader()
//{
//    ID3DBlob* ErrorCode;
//    // 버텍스 쉐이더 컴파일
//    HRESULT hResult = D3DCompileFromFile(
//        L"VertexShader.vsh",
//        nullptr,
//        nullptr,
//        "VS",
//        "vs_5_0",
//        0,
//        0,
//        &mVertexShaderCode,
//        &ErrorCode);
//    if (FAILED(hResult))
//    {
//        return hResult;
//    }
//    hResult = mDevice->CreateVertexShader(
//        mVertexShaderCode->GetBufferPointer(),
//        mVertexShaderCode->GetBufferSize(),
//        nullptr,
//        &mVS);
//
//    if (ErrorCode) ErrorCode->Release();
//    return hResult;
//}
//
//HRESULT Object::LoadPixelShader()
//{
//    ID3DBlob* ShaderCode;
//    ID3DBlob* ErrorCode;
//    // 픽셀 쉐이더 컴파일
//    HRESULT hResult = D3DCompileFromFile(
//        L"PixelShader.psh",
//        nullptr,
//        nullptr,
//        "PS",
//        "ps_5_0",
//        0,
//        0,
//        &ShaderCode,
//        &ErrorCode);
//    if (FAILED(hResult))
//    {
//        return hResult;
//    }
//    hResult = mDevice->CreatePixelShader(
//        ShaderCode->GetBufferPointer(),
//        ShaderCode->GetBufferSize(),
//        nullptr,
//        &mPS);
//
//    if (ShaderCode) ShaderCode->Release();
//    if (ErrorCode) ErrorCode->Release();
//    return hResult;
//}
//
//HRESULT Object::InputLayout()
//{
//	const D3D11_INPUT_ELEMENT_DESC layout[] =
//	{
//		{ "POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
//	};
//
//	UINT numCount = sizeof(layout) / sizeof(layout[0]);
//	HRESULT hResult = mDevice->CreateInputLayout(
//		layout,
//		numCount,
//		mVertexShaderCode->GetBufferPointer(), 
//		mVertexShaderCode->GetBufferSize(), 
//		&mVertexLayout);
//
//	return hResult;
//}
//
//bool Object::Init() 
//{
//	CreateVertexBuffer();
//	LoadVertexShader();
//	LoadPixelShader();
//	InputLayout();
//	return true;
//}
//
//bool Object::Frame() 
//{
//	return false;
//}
//
//bool Object::Render() 
//{
//	mImmediateContext->IASetInputLayout(mVertexLayout);
//	mImmediateContext->VSSetShader(mVS, NULL, 0);
//	mImmediateContext->PSSetShader(mPS, NULL, 0);
//	UINT stride = sizeof(P3VERTEX);
//	UINT offset = 0;
//	mImmediateContext->IASetVertexBuffers(0, 1, &mVertexBuffer, &stride, &offset);
//	mImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
//	mImmediateContext->Draw(verticles.size(), 0);
//	return true;
//}
//
//bool Object::Release() 
//{
//	if (mVertexBuffer) mVertexBuffer->Release();
//	if (mVertexLayout) mVertexLayout->Release();
//	if (mVS) mVS->Release();
//	if (mPS) mPS->Release();
//	return true;
//}