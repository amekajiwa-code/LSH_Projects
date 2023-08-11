#pragma once
#include "Core.h"
#include <DXGI.h>

class sample : public Core {
private:
	//
public:
	bool  Init();
	bool  Frame();
	bool  Render();
	bool  Release();
};