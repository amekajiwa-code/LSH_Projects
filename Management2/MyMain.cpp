//1. 검색함수(삭제,수정으로 연계) -> 거의 해결
//2. 문자열 갈라서 Student 멤버변수에 넣는 함수(Load, Insert연계)
//2.5 정렬할때 원본유지하기
//3. 최종작업 클래스 분리
#include <iostream>

using namespace std;

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
	MyLinkedList<MyStudent>* list = new MyLinkedList<MyStudent>;
	int ID = 0;
	while (true) {
		int select = -1;
		cout << "----------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Initialize = 0 Print = 1 Find = 2 Save = 3 Load = 4 Insert = 5 Delete = 6 Update = 7 Sort = 8 Exit = 99" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------" << endl;
		cin >> select;

		if (select == Exit) {
			break;
		}

		switch (select)
		{
		case Initialize: {
			MenuClear();
			list->DestroyNode();
			ID = 0;
			for (int i = 0; i < 10; ++i) {
				MyStudent dummy("dummy", ID, 50 + i, 60 + i, 40 + i);
				Node<MyStudent>* newNode = list->CreateNode(dummy, ID++);
				list->PushFront(newNode);
			}
			cout << "데이터가 초기화 되었습니다." << endl;
			break;
		}
		case Print: {
			MenuClear();
			Node<MyStudent>* node;
			node = list->mHeadNode.mNextNode;
			cout << left << setw(7) << "Name"
				<< setw(5) << "ID" << setw(5) << "Kor"
				<< setw(5) << "Eng" << setw(5) << "Mat"
				<< setw(5) << "Tot" << setw(5) << "Avg" << endl;
			while (node != nullptr) {
				cout << left << node->mData.PrintStudent() << endl;
				node = node->mNextNode;
			}
			break;
		}
		case Find: {
			MenuClear();
			int input = -1;
			cout << "Find - Target ID : ";
			cin >> input;
			Node<MyStudent>* findNode;
			findNode = list->FindNode(input);
			if (findNode != nullptr) {
				cout << "검색된 학생 : " << findNode->mData.PrintStudent() << endl;
			}
			break;
		}
		case Save: {
			MenuClear();
			string fileName = "";
			cout << "세이브 파일명 : ";
			cin >> fileName;
			string output = "";
			Node<MyStudent>* node = list->mHeadNode.mNextNode;
			while (node != nullptr) {
				output += node->mData.PrintStudent();
				output += "\n";
				node = node->mNextNode;
			}
			FileIO fo;
			fo.SaveFile(fileName, output);
			break;
		}
		case Load: {
			MenuClear();
			break;
		}
		case Insert: {
			MenuClear();
			cout << "입력 순서 : 이름 국어 영어 수학 : ";
			string name;
			int kor, eng, mat;
			cin >> name >> kor >> eng >> mat;
			MyStudent dummy(name, ID, kor, eng, mat);
			Node<MyStudent>* newNode = list->CreateNode(dummy, ID++);
			cout << "삽입될 학생의 ID : " << endl;
			int input = -1;
			cin >> input;
			Node<MyStudent>* findNode;
			findNode = list->FindNode(input);
			list->InsertNode(findNode, newNode);
			break;
		}
		case Delete: {
			MenuClear();
			int input = -1;
			cout << "삭제하고 싶은 학생의 ID : ";
			cin >> input;
			Node<MyStudent>* findNode = list->FindNode(input);
			if (findNode != nullptr) {
				list->DeleteNode(findNode);
			}
			break;
		}
		case Update: {
			MenuClear();
			int input = -1;
			cout << "입력 순서 : 이름 국어 영어 수학 : ";
			string name;
			int kor, eng, mat;
			cin >> name >> kor >> eng >> mat;
			MyStudent dummy(name, ID, kor, eng, mat);
			cout << "수정하고 싶은 학생의 ID : ";
			cin >> input;
			Node<MyStudent>* findNode = list->FindNode(input);
			if (findNode != nullptr) {
				findNode->mData = dummy;
			}
			cout << "데이터가 수정되었습니다." << endl;
			break;
		}
		case Sort: {
			MenuClear();
			MergeSort<MyStudent> ms;
			ms.merge_sort(&list->mHeadNode.mNextNode, list->GetLength());
			cout << "데이터가 정렬되었습니다." << endl;
			break;
		}
		default: {
			MenuClear();
			break;
		}
		}
	}
	
	delete list;
	list = nullptr;
}