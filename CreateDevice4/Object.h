#pragma once
#include "Window.h"

struct P3VERTEX {
	float x;
	float y;
	float z;
	float u;
	float v;
};

class Object {
private:
	ID3D11Device* mDevice = nullptr;
	ID3D11DeviceContext* mImmediateContext = nullptr;
public:
	ID3D11Buffer* mVertexBuffer = nullptr;
	ID3DBlob* mVertexShaderCode = nullptr;
	ID3D11InputLayout* mVertexLayout = nullptr;
	ID3D11VertexShader* mVS = nullptr;
	ID3D11PixelShader* mPS = nullptr;

	ID3D11ShaderResourceView* mTexSRV = nullptr;

	std::vector<P3VERTEX> verticles;

	void Set(ID3D11Device* device, ID3D11DeviceContext* immediateContext);
	bool  Create(std::wstring texFileName);
	bool  LoadTextureFile(std::wstring fileName);

	HRESULT CreateVertexBuffer();
	HRESULT LoadVertexShader();
	HRESULT LoadPixelShader();
	HRESULT InputLayout();

	bool Init();
	bool Frame();
	bool Render();
	bool Release();

	Object() {};
	~Object() {};
};