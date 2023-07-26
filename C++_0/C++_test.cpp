#include <iostream>
#include <windows.h>
#pragma comment (lib, "Winmm.lib")

int main() {
    DWORD startTime = timeGetTime();

    // 시간이 경과하는 동안 작업 수행
    
    // 프로그램 1초 일시정지
    Sleep(1000);

    DWORD endTime = timeGetTime();
    DWORD elapsedTime = endTime - startTime;
    std::cout << "경과 시간: " << elapsedTime << "ms" << std::endl;

    return 0;
}