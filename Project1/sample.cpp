#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_PAINT:
        //
    default:
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // 사각형 그리기
        RECT rect;
        rect.left = 100;    // 사각형의 좌상단 X 좌표
        rect.top = 100;     // 사각형의 좌상단 Y 좌표
        rect.right = 300;   // 사각형의 우하단 X 좌표
        rect.bottom = 200;  // 사각형의 우하단 Y 좌표

        // 사각형 색상 설정
        HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255)); // 빨간색
        HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);

        // 사각형 그리기
        Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    WNDCLASSEXW wcex;
    ZeroMemory(&wcex, sizeof(wcex));
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.hInstance = hInstance;
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszClassName = L"윈도우";
    WORD ret = RegisterClassExW(&wcex);

    HWND hWnd = CreateWindowW(L"윈도우", L"타이틀", WS_OVERLAPPEDWINDOW,
        0, 0, 800, 600, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    ::MessageBox(NULL, L"프로그램 종료", L"title", MB_OK);
    return 0;
}