#include <Windows.h>

// 윈도우 클래스 이름
const wchar_t* g_WindowClassName = L"GameWindow";


// 윈도우 핸들러
HWND g_hWnd;

// 플레이어 캐릭터의 위치
int g_PlayerX = 100;
int g_PlayerY = 100;

// 윈도우 프로시저 콜백 함수
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_KEYDOWN:
        // 키보드 입력 처리
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
        // 화면 갱신
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // 플레이어 캐릭터 그리기
        RECT playerRect = { g_PlayerX, g_PlayerY, g_PlayerX + 50, g_PlayerY + 50 };
        HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0)); // 빨간색 정사각형
        FillRect(hdc, &playerRect, brush);
        DeleteObject(brush);

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_CLOSE:
        // 윈도우 종료 메시지 처리
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // 윈도우 클래스 등록
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

    // 윈도우 생성
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

    // 윈도우 표시
    ShowWindow(g_hWnd, nCmdShow);
    UpdateWindow(g_hWnd);

    // 메시지 루프
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}