#pragma once
#include "Mecro.h"

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
	bool Run();

	Window() {};
	virtual ~Window() {};
};