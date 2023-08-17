#pragma once
#include "Core.h";
#include "Object.h"

class sample : public Core
{
	Object* obj;
public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();
};