#pragma once
#include <windows.h>
#include <d3d11.h>
#pragma comment (lib, "d3d11.lib") // d3d11.dll

#include <string>
class Window
{
public:
	HINSTANCE mHInstance = 0; // 인스턴스 핸들
	HWND mHWnd = 0; // 윈도우 핸들
	DWORD mDwExStyle = 0;
	DWORD mDwStyle = WS_OVERLAPPEDWINDOW; // 윈도우 스타일
	DWORD mDwWindowPosX = 0;
	DWORD mDwWindowPosY = 0;
	DWORD mDwWindowWidth = 0;
	DWORD mDwWindowHeight = 0; // 윈도우 위치, 크기

	bool SetRegisterWindow(HINSTANCE hInstance);
	bool SetWindow(const WCHAR* szTitle, DWORD dwWindowWidth = 800, DWORD dwWindowHeight = 600);
	virtual ~Window() {

	};
};

