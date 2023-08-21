#pragma once
#include <ctime>
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>

#pragma comment (lib, "d3d11.lib") // d3d11.dll
#pragma comment (lib, "dxgi.lib") // d3d11.dll
#pragma comment (lib, "d3dcompiler.lib") // d3d11.dll
#pragma comment (lib, "DirectXTex.lib") // DirectXTex.h

#include <string>
#include <vector>
#include <memory>
<<<<<<< HEAD
#include <unordered_map>

#include "GeometryUtils.h"

#define randstep(fmin, fmax) ((float)fmin+((float)fmax-(float)fmin)* rand() / RAND_MAX)

using namespace std;
=======
>>>>>>> parent of 1a1c732 (ë¸”ë Œë”©)

class Window
{
public:
	HINSTANCE mHInstance = 0; // ÀÎ½ºÅÏ½º ÇÚµé
	HWND mHWnd = 0; // À©µµ¿ì ÇÚµé
	DWORD mDwExStyle = 0;
	DWORD mDwStyle = WS_OVERLAPPEDWINDOW; // À©µµ¿ì ½ºÅ¸ÀÏ
	DWORD mDwWindowPosX = 0;
	DWORD mDwWindowPosY = 0;
	DWORD mDwWindowWidth = 0;
	DWORD mDwWindowHeight = 0; // À©µµ¿ì À§Ä¡, Å©±â

	bool SetRegisterWindow(HINSTANCE hInstance);
	bool SetWindow(const WCHAR* szTitle, DWORD dwWindowWidth, DWORD dwWindowHeight);
	virtual ~Window() {

	};
};

