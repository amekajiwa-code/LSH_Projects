#include <iostream>
using namespace std;

#include "MyLinkedList.h"
#include "MyStudent.h"

int main() {
	MyLinkedList<MyStudent>* list = new MyLinkedList<MyStudent>;
	for (int i = 0; i < 5; ++i) {
		MyStudent dummy("x", i, 90, 80, 70);
		Node<MyStudent>* newNode = list->CreateNode(dummy);
		list->PushFront(newNode);
	}
	delete list;
	list = nullptr;
}