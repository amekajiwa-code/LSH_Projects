#pragma once
#include "Window.h"
#include "TextureManager.h"
#include "ShaderManager.h"

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
	ID3D11InputLayout* mVertexLayout = nullptr;
	const Shader* mShader = nullptr;
	const Texture* mTexture = nullptr;

	vector<P3VERTEX> verticles;

	void Set(ID3D11Device* device, ID3D11DeviceContext* immediateContext);
	bool  Create(TextureManager& texMg, wstring texFileName, ShaderManager& shaMg, wstring shaFileName);

	bool CreateVertexBuffer();
	bool InputLayout();

	bool Init();
	bool Frame();
	bool Render();
	bool Release();

	Object() {};
	~Object() {};
};