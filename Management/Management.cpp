#include "Management.h"
//고쳐야될것 : 병합정렬 매개변수인자 오류 lvalue nextNode private로 감췄을때 오류 발생함
int main()
{
	LinkedList* list = new LinkedList();
	MergeSort ms;
	FileIO io;
	for (int i = 0; i < 10; ++i) {
		Node* newNode = list->CreateNode(i, i * 10);
		list->PushFront(newNode);
	}
	ms.merge_sort(&list->headNode.nextNode, 10);
	cout << list->headNode.GetNextNode()->GetId() << endl;
	//ms.merge_sort(&list->headNode.GetNextNode(), 10);
	list->PrintNode();
	io.SaveFile(&list->headNode);
	delete list;
	LinkedList* list2 = new LinkedList();
	io.LoadFile(list2);
	list2->PrintNode();
	delete list2;
}

