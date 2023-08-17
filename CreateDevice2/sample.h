#pragma once
#include "Core.h";
#include "Object.h"

class sample : public Core
{
	TextureManager mTexMg;
	ShaderManager mShaMg;
	ID3D11BlendState* mAlphaBlend = nullptr;
	Object* obj;
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};