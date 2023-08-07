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

        // �簢�� �׸���
        RECT rect;
        rect.left = 100;    // �簢���� �»�� X ��ǥ
        rect.top = 100;     // �簢���� �»�� Y ��ǥ
        rect.right = 300;   // �簢���� ���ϴ� X ��ǥ
        rect.bottom = 200;  // �簢���� ���ϴ� Y ��ǥ

        // �簢�� ���� ����
        HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255)); // ������
        HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);

        // �簢�� �׸���
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
    wcex.lpszClassName = L"������";
    WORD ret = RegisterClassExW(&wcex);

    HWND hWnd = CreateWindowW(L"������", L"Ÿ��Ʋ", WS_OVERLAPPEDWINDOW,
        0, 0, 800, 600, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);

    MSG msg;

    // �⺻ �޽��� �����Դϴ�:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    ::MessageBox(NULL, L"���α׷� ����", L"title", MB_OK);
    return 0;
}