#include "MyLinkedList.h"
#include "MyStudent.h"

int main() {
	MyLinkedList<MyStudent> list;
	MyStudent dummy("dummy", 1, 90, 80, 70);
	Node<MyStudent>* newNode = list.CreateNode(dummy);
	list.PushBack(newNode);
	MyStudent dummy2("dummy2", 2, 90, 80, 70);
	Node<MyStudent>* newNode2 = list.CreateNode(dummy2);
	list.PushBack(newNode2);
	MyStudent dummy3("dummy3", 3, 90, 80, 70);
	Node<MyStudent>* newNode3 = list.CreateNode(dummy3);
	list.PushBack(newNode3);
}