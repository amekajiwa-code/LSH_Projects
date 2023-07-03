#include "MyManager.h"

enum eMenu {
	Initialize = 0,
	Print = 1,
	Find = 2,
	Save = 3,
	Load = 4,
	Insert = 5,
	Delete = 6,
	Update = 7,
	Sort = 8,
	Exit = 99
};

inline void MenuClear()
{
	system("cls");
}

int main() {
	MyManager* manager = new MyManager();

	while (true) {
		int select = -1;
		cout << left << setw(30) << setfill(' ') << "" << endl;
		cout << setw(10) << "�ʱ�ȭ" << setw(5) << "0";
		cout << setw(10) << "���" << setw(5) << "1";
		cout << setw(10) << "�˻�" << setw(5) << "2" << endl;
		cout << setw(10) << "����" << setw(5) << "3";
		cout << setw(10) << "�ҷ�����" << setw(5) << "4";
		cout << setw(10) << "����" << setw(5) << "5" << endl;
		cout << setw(10) << "����" << setw(5) << "6";
		cout << setw(10) << "����" << setw(5) << "7";
		cout << setw(10) << "����" << setw(5) << "8" << endl;
		cout << setw(10) << "Exit" << setw(5) << "99" << endl;
		cout << left << setw(30) << setfill(' ') << "" << endl;
		
		while (!(cin >> select)) {
			cin.clear();
			while (cin.get() != '\n') {
				if (cin.bad()) {
					cin.clear();
				}
			}
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���: ";
		}

		if (select == Exit) {
			break;
		}

		switch (select)
		{
		case Initialize: {
			MenuClear();
			manager->Initialize();
			break;
		}
		case Print: {
			MenuClear();
			manager->Print();
			break;
		}
		case Find: {
			MenuClear();
			manager->Find();
			break;
		}
		case Save: {
			MenuClear();
			manager->Save();
			break;
		}
		case Load: {
			MenuClear();
			manager->Load();
			break;
		}
		case Insert: {
			MenuClear();
			manager->Insert();
			break;
		}
		case Delete: {
			MenuClear();
			manager->Delete();
			break;
		}
		case Update: {
			MenuClear();
			manager->Update();
			break;
		}
		case Sort: {
			MenuClear();
			manager->Sort();
			break;
		}
		default: {
			MenuClear();
			break;
		}
		}
	}

	delete manager;
}