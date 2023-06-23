#include "Management.h"
//���ľߵɰ� : �������� �Ű��������� ���� lvalue nextNode private�� �������� ���� �߻���
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

