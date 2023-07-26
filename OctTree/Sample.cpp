#include <iostream>
#include "Timer.h"

using namespace std;

void main() {
	Timer g_Timer;
	g_Timer.Init();
	while (true) {
		g_Timer.Frame();
		cout << "흐른시간 : " << g_Timer.mSecondPerFrame
			<< "\n축적시간 : " << g_Timer.mTimer;
		Sleep(1000);
		system("cls");
	}
	
}