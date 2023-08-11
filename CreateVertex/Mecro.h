#pragma once
#include <windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>
#pragma comment (lib, "d3d11.lib") // d3d11.dll
#pragma comment (lib, "dxgi.lib") // d3d11.dll
#pragma comment (lib, "d3dcompiler.lib") // d3d11.dll

#include <string>
#include <vector>

#define GAME_START int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR    lpCmdLine, int       nCmdShow){ Sample win;
#define GAME_REGISTER      win.SetRegisterClassWindow(hInstance);
#define GAME_WINDOW(s,w,h) win.SetWindow(L#s, w, h);
#define GAME_RUN win.Run();
#define GAME_END return 0; };

#define GAME(s,w,h) GAME_START;GAME_REGISTER;GAME_WINDOW(s,w,h);GAME_RUN;GAME_END;