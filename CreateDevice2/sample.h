#pragma once
#include "Core.h";
#include "PlaneObject.h"

class sample : public Core
{
<<<<<<< HEAD
	TextureManager mTexMg;
	ShaderManager mShaMg;
	ID3D11BlendState* mAlphaBlend = nullptr;

	Object* obj = nullptr;
	vector<Object*> mNPCs;

	Matrix mMatView;
	Matrix mMatOrthonormalProjection;
	Vector3 mCameraPos;
=======
	Object* obj;
>>>>>>> parent of 1a1c732 (블렌딩)
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};