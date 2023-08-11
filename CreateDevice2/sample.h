#pragma once
#include "Core.h"

struct P3VERTEX {
	float x;
	float y;
	float z;
};

class sample : public Core {
private:

public:
	ID3D11Buffer* mVertexBuffer = nullptr;//
	ID3DBlob* mVertexShaderCode = nullptr;//
	ID3D11InputLayout* mVertexLayout = nullptr;//
	ID3D11VertexShader* mVS = nullptr;//
	ID3D11PixelShader* mPS = nullptr;//
	std::vector<P3VERTEX> verticles;//

	HRESULT CreateVertexBuffer();
	HRESULT LoadVertexShader();
	HRESULT LoadPixelShader();
	HRESULT InputLayout();

	bool Init();
	bool Frame();
	bool Render();
	bool Release();

	sample() {};
	~sample() {};
};