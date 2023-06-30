//2.5 정렬할때 원본유지하기 (연결리스트 -> 일반배열로 복사후 정렬)
//3. 최종작업 클래스 분리
//4. 잘못된 입력들어왔을때 처리
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
		cout << "초기화 = 0 출력 = 1 검색 = 2 저장 = 3 불러오기 = 4 삽입 = 5 삭제 = 6 수정 = 7 정렬 = 8 Exit = 99" << endl;
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
			cout << left << setw(5) << "Name"
				<< setw(3) << "ID" << setw(3) << "Kor"
				<< setw(3) << "Eng" << setw(3) << "Mat"
				<< setw(3) << "Tot" << setw(3) << "Avg" << endl;
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
			else {
				cout << "검색된 학생이 없습니다." << endl;
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
			list->DestroyNode();
			ID = 0;
			string name;
			int kor, eng, mat;
			string fileName = "";
			cout << "불러올 파일명 : ";
			cin >> fileName;
			FileIO fi;
			string text = fi.LoadFile(fileName);
			if (text == "failed") {
				cout << "파일 읽어오는데 실패했습니다." << endl;
				continue;
			}
			string member = "";
			string buffer = "";
			int spaceCounter = 0;
			int index = 0;
			Utility ut;
			while (true) {
				if (index > text.size()) {
					break; //종료조건
				}
				//공백이면 ++
				buffer += text[index];
				if (text[index] == ' ') {
					++spaceCounter;
					// 1 3 4 5면 각 멤버변수에 해당하는 위치
					switch (spaceCounter) {
					case 1: {
						name = member;
						member = "";
						break;
					}
					case 2: {
						member = "";
						break;
					}
					case 3: {
						kor = ut.StringToInt(member);
						member = "";
						break;
					}
					case 4: {
						eng = ut.StringToInt(member);
						member = "";
						break;
					}
					case 5: {
						mat = ut.StringToInt(member);
						member = "";
						break;
					}
					default: {
						break;
					}
					}
				}
				else {
					member += text[index];
				}
				
				//초기화
				if (spaceCounter > 6) {
					MyStudent dummy(name, ID, kor, eng, mat);
					Node<MyStudent>* newNode = list->CreateNode(dummy, ID++);
					list->PushBack(newNode);
					member = "";
					buffer = "";
					spaceCounter = 0;
				}
				//index 순회
				++index;
			}
			cout << "데이터가 로드 되었습니다." << endl;
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

			cout << "입력 방법 : 1. 후위 2. 전위. 3. 중간삽입 : ";
			int inputOption = -1;
			cin >> inputOption;
			switch (inputOption)
			{
			case 1: {
				list->PushBack(newNode);
				break;
			}
			case 2: {
				list->PushFront(newNode);
				break;
			}
			case 3: {
				cout << "삽입될 학생의 ID : ";
				int inputID = -1;
				cin >> inputID;
				Node<MyStudent>* findNode;
				findNode = list->FindNode(inputID);
				if (findNode != nullptr) {
					list->InsertNode(findNode, newNode);
				}
				else {
					cout << "검색된 학생이 없습니다." << endl;
				}
				break;
			}
			default:
				break;
			}

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
			else {
				cout << "검색된 학생이 없습니다." << endl;
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
			else {
				cout << "검색된 학생이 없습니다." << endl;
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