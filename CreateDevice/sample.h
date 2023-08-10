#pragma once
#include "Core.h"
#include <DXGI.h>

class MyDevice : public Core {
public:
	IDXGIFactory* mFactory = nullptr;
	ID3D11Device* mDevice = nullptr;
	ID3D11DeviceContext* mImmediateContext = nullptr;
	IDXGISwapChain* mSwapChain = nullptr;
	ID3D11RenderTargetView* mRenderTargetView = nullptr;
	D3D11_VIEWPORT mViewPort;

	MyDevice() {};
	~MyDevice() {};

	HRESULT CreateDevice();
	HRESULT CreateFactory();
	HRESULT CreateSwapChain();
	HRESULT SetRenderTargetView();
	HRESULT SetViewPort();
};

class sample : public MyDevice {
public:
	bool  Init();
	bool  Frame();
	bool  Render();
	bool  Release();

	sample() {}
	~sample() {}
};