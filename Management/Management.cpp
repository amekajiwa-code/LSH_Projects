#include "Management.h"
//���ľߵɰ� : �������� �Ű��������� ���� lvalue nextNode private�� �������� ���� �߻���
int main()
{
	Student st("asd", 0);
	st.SetScore(90, 80, 70);
	st.Print();
	//LinkedList* list = new LinkedList();
	//MergeSort ms;
	//for (int i = 0; i < 10; ++i) {
	//	Node* newNode = list->CreateNode(i, i * 10);
	//	list->PushFront(newNode);
	//}
	//ms.merge_sort(&list->headNode.nextNode, 10);
	//cout << list->headNode.GetNextNode()->GetId() << endl;
	////ms.merge_sort(&list->headNode.GetNextNode(), 10);
	//list->PrintNode();
	//list->Save();
	//delete list;
	//LinkedList* list2 = new LinkedList();
	//list2->Load();
	//list2->PrintNode();
	//delete list2;
}

