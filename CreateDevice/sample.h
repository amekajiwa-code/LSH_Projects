#pragma once
#include "Core.h"
#include <DXGI.h>

struct P3VERTEX
{
	float x;
	float y;
	float z;
};

class MyDevice : public Core {
public:
	IDXGIFactory* mFactory = nullptr;
	ID3D11Device* mDevice = nullptr;
	ID3D11DeviceContext* mImmediateContext = nullptr;
	IDXGISwapChain* mSwapChain = nullptr;
	ID3D11RenderTargetView* mRenderTargetView = nullptr;
	D3D11_VIEWPORT mViewPort;

	ID3D11Buffer* mVertexBuffer = nullptr;
	ID3D11InputLayout* mVertexLayout = nullptr;
	ID3D11VertexShader* mVertexShader = nullptr;
	ID3D11PixelShader* mPixelShader = nullptr;

	std::vector<P3VERTEX> mVertices;

	MyDevice() {};
	~MyDevice() {};

	HRESULT CreateDevice();
	HRESULT CreateFactory();
	HRESULT CreateSwapChain();
	HRESULT SetRenderTargetView();
	HRESULT SetViewPort();

	HRESULT CreateVertexBuffer();
	HRESULT LoadShaderAndInputLayout();
};

class sample : public MyDevice {
public:
	sample() {}
	~sample() {}

	bool  Init();
	bool  Frame();
	bool  Render();
	bool  Release();
};