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
#include "DirectXTex.h"

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

#include "GeometryUtils.h"

#define randstep(fmin, fmax) ((float)fmin+((float)fmax-(float)fmin)* rand() / RAND_MAX)

using namespace std;

class Window
{
public:
	HINSTANCE mHInstance = 0; // �ν��Ͻ� �ڵ�
	HWND mHWnd = 0; // ������ �ڵ�
	DWORD mDwExStyle = 0;
	DWORD mDwStyle = WS_OVERLAPPEDWINDOW; // ������ ��Ÿ��
	DWORD mDwWindowPosX = 0;
	DWORD mDwWindowPosY = 0;
	DWORD mDwWindowWidth = 0;
	DWORD mDwWindowHeight = 0; // ������ ��ġ, ũ��

	bool SetRegisterWindow(HINSTANCE hInstance);
	bool SetWindow(const WCHAR* szTitle, DWORD dwWindowWidth, DWORD dwWindowHeight);
	virtual ~Window() {

	};
};

