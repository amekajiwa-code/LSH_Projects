#include "Window.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) // ������ ���ν���
{
    switch (message) //�޽����� ���� ����
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

bool Window::SetRegisterWindow(HINSTANCE hInstance) // ������ Ŭ���� ���
{
    mHInstance = hInstance;
    WNDCLASSEX wcex; // ������Ŭ���� Ư������ ����ü
    ZeroMemory(&wcex, sizeof(wcex));
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc; //���������ν��� �����̺�Ʈ->�޼���ť ����
    wcex.hInstance = hInstance;
    wcex.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));// (COLOR_WINDOW + 1);
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.lpszClassName = L"������";
    WORD ret = RegisterClassExW(&wcex); // ����ü �����Ͽ� ������ Ŭ���� ���
    return true;
}

bool Window::SetWindow(const WCHAR* szTitle, DWORD dwWindowWidth, DWORD dwWindowHeight) // ������ �����ѵ� ������ ���
{
    mDwWindowWidth = dwWindowWidth;
    mDwWindowHeight = dwWindowHeight;
    mDwWindowPosX = 1920 / 2 - dwWindowWidth / 2;
    mDwWindowPosY = 1080 / 2 - dwWindowHeight / 2;
#ifndef _DEBUG
    dwExStyle = WS_EX_TOPMOST;
    dwStyle = WS_POPUPWINDOW;
#else
    mDwExStyle = WS_EX_APPWINDOW;
#endif
    mHWnd = CreateWindowEx(mDwExStyle, L"������", szTitle, mDwStyle,
        mDwWindowPosX, mDwWindowPosY, mDwWindowWidth, mDwWindowHeight,
        nullptr, nullptr, mHInstance, nullptr);

    if (!mHWnd)
    {
        return FALSE;
    }

    ShowWindow(mHWnd, SW_SHOWNORMAL);
    return true;
}