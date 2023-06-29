#include <iostream>
using namespace std;

#include "MyManager.h"
#include "MyLinkedList.h"
#include "MyStudent.h"
#include "MyMergeSort.h"
#include "MyFileIO.h"

enum eMenu {
	Initialize = 0,
	Print = 1,
	Find = 2,
	Save = 3,
	Load = 4,
	Push = 5,
	Insert = 6,
	Delete = 7,
	Update = 8,
	Sort = 9,
	Exit = 99
};

int main() {
	while (true) {
		int select = -1;
		cin >> select;
		switch (select)
		{
		case Initialize:
			break;
		case Print:
			break;
		case Find:
			break;
		case Save:
			break;
		case Load:
			break;
		case Push:
			break;
		case Insert:
			break;
		case Delete:
			break;
		case Update:
			break;
		case Sort:
			break;
		case Exit:
			break;
		default:
			break;
		}
	}
	MyLinkedList<MyStudent>* list = new MyLinkedList<MyStudent>;
	for (int i = 0; i < 10; ++i) {
		MyStudent dummy("x", i, 90, 80, 70);
		Node<MyStudent>* newNode = list->CreateNode(dummy, i);
		list->PushFront(newNode);
	}

	MergeSort<MyStudent> ms;
	ms.merge_sort(&list->mHeadNode.mNextNode, 10);
	delete list;
	list = nullptr;
}