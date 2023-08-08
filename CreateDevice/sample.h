#pragma once
#include "Core.h"
#include <d3d11.h>
#pragma comment (lib, "d3d11.lib") // d3d11.dll

class sample : public Core {
private:
	IDXGISwapChain* mSwapChain = nullptr;
	ID3D11Device* mDevice = nullptr;
	ID3D11DeviceContext* mImmediateContext = nullptr;
	ID3D11RenderTargetView* mRenderTargetView = nullptr;
public:
	bool  Init();
	bool  Frame();
	bool  Render();
	bool  Release();
};