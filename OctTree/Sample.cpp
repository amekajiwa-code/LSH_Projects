#include <iostream>
#include "Timer.h"

using namespace std;

void main() {
	Timer g_Timer;
	g_Timer.Init();
	while (true) {
		g_Timer.Frame();
		cout << "�帥�ð� : " << g_Timer.mSecondPerFrame
			<< "\n�����ð� : " << g_Timer.mTimer;
		Sleep(1000);
		system("cls");
	}
	
}