#pragma once
#include "Window.h"

struct P3VERTEX {
	Vector3 p; // xyz
	Vector2 t; // uv
};

struct MatrixData
{
	Matrix matWorld; // Scale
	Matrix matView; // Rotation
	Matrix matProjection; // Translate
};

class Object {
public:
	Matrix mMatWorld;
	Matrix mMatView;
	Matrix mMatProjection;
	MatrixData mMatData;

	Vector3 mPos;
	Vector3 mScale;
	Vector3 mRotation;

	ID3D11Device* mDevice = nullptr;
	ID3D11DeviceContext* mImmediateContext = nullptr;
public:
	ID3D11Buffer* mVertexBuffer = nullptr;
<<<<<<< HEAD
	ID3D11Buffer* mConstantBuffer = nullptr;
=======
	ID3DBlob* mVertexShaderCode = nullptr;
>>>>>>> parent of 1a1c732 (블렌딩)
	ID3D11InputLayout* mVertexLayout = nullptr;
	ID3D11VertexShader* mVS = nullptr;
	ID3D11PixelShader* mPS = nullptr;

	ID3D11ShaderResourceView* mTexSRV = nullptr;

	std::vector<P3VERTEX> verticles;

	void Set(ID3D11Device* device, ID3D11DeviceContext* immediateContext);
<<<<<<< HEAD
	bool Create(TextureManager& texMg, wstring texFileName, ShaderManager& shaMg, wstring shaFileName);

	void SetPos(Vector3 pos);
	void SetScale(Vector3 scale);
	void SetMatrix(Matrix* matWorld, Matrix* matView, Matrix* matProjection);
=======
	bool  Create(std::wstring texFileName);
	bool  LoadTextureFile(std::wstring fileName);

	HRESULT CreateVertexBuffer();
	HRESULT LoadVertexShader();
	HRESULT LoadPixelShader();
	HRESULT InputLayout();
>>>>>>> parent of 1a1c732 (블렌딩)

	virtual void Move(float second) {};

	virtual bool CreateVertexBuffer();
	virtual bool CreateConstantBuffer();
	virtual bool InputLayout();

	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();
	virtual bool Release();

	Object() {};
	~Object() {};
};