#pragma once
#include "Core.h"
#include <DXGI.h>

class MyDevice {
	
};

class MySwapChain {
	
};

class sample : public Core {
private:
	IDXGIFactory* mFactory = nullptr;
	ID3D11Device* mDevice = nullptr;
	ID3D11DeviceContext* mImmediateContext = nullptr;
	IDXGISwapChain* mSwapChain = nullptr;
	ID3D11RenderTargetView* mRenderTargetView = nullptr;
	D3D11_VIEWPORT mViewPort;
public:
	bool  Init();
	bool  Frame();
	bool  Render();
	bool  Release();
};