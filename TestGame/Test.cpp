#include <Windows.h>

// ������ Ŭ���� �̸�
const wchar_t* g_WindowClassName = L"GameWindow";


// ������ �ڵ鷯
HWND g_hWnd;

// �÷��̾� ĳ������ ��ġ
int g_PlayerX = 100;
int g_PlayerY = 100;

// ������ ���ν��� �ݹ� �Լ�
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_KEYDOWN:
        // Ű���� �Է� ó��
        switch (wParam) {
        case VK_LEFT:
            g_PlayerX -= 10;
            break;
        case VK_RIGHT:
            g_PlayerX += 10;
            break;
        case VK_UP:
            g_PlayerY -= 10;
            break;
        case VK_DOWN:
            g_PlayerY += 10;
            break;
        }
        // ȭ�� ����
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // �÷��̾� ĳ���� �׸���
        RECT playerRect = { g_PlayerX, g_PlayerY, g_PlayerX + 50, g_PlayerY + 50 };
        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0)); // ������ ���簢��
        FillRect(hdc, &playerRect, brush);
        DeleteObject(brush);

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_CLOSE:
        // ������ ���� �޽��� ó��
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // ������ Ŭ���� ���
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = NULL;
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = g_WindowClassName;
    wcex.hIconSm = NULL;

    if (!RegisterClassEx(&wcex)) {
        MessageBox(NULL, "Failed to register window class.", "Error", MB_OK | MB_ICONERROR);
        return 1;
    }

    // ������ ����
    g_hWnd = CreateWindow(
        g_WindowClassName,
        "2D Game",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (g_hWnd == NULL) {
        MessageBox(NULL, "Failed to create window.", "Error", MB_OK | MB_ICONERROR);
        return 1;
    }

    // ������ ǥ��
    ShowWindow(g_hWnd, nCmdShow);
    UpdateWindow(g_hWnd);

    // �޽��� ����
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}