#include <iostream>
#include <windows.h>
#pragma comment (lib, "Winmm.lib")

int main() {
    DWORD startTime = timeGetTime();

    // �ð��� ����ϴ� ���� �۾� ����
    
    // ���α׷� 1�� �Ͻ�����
    Sleep(1000);

    DWORD endTime = timeGetTime();
    DWORD elapsedTime = endTime - startTime;
    std::cout << "��� �ð�: " << elapsedTime << "ms" << std::endl;

    return 0;
}