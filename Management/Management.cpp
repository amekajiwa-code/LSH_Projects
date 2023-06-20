#include "Management.h"

int main()
{
	LinkedList list;
	MergeSort ms;
	/*for (int i = 0; i < 5; ++i) {
		Node* newNode = list.CreateNode(i, i * 10);
		list.PushFront(newNode);
	}*/
	list.Load();
	ms.merge_sort(&list.headNode.nextNode, 5);
	list.PrintNode();
}

LinkedList::LinkedList()
	: headNode{ -1, -1, nullptr, nullptr }
	, tailNode(&headNode)
{
}

LinkedList::~LinkedList()
{
	DestroyNode();
}

Node* LinkedList::CreateNode(int id, int value) {
	Node* newNode = new Node;
	newNode->id = id;
	newNode->value = value;
	newNode->nextNode = nullptr;
	newNode->preNode = nullptr;
	return newNode;
}

Node* LinkedList::find_node(int id) {
	Node* Node = headNode.nextNode;
	while (Node != NULL) {
		if (Node->id == id) {
			return Node;
		}
		Node = Node->nextNode;
	}
	return NULL;
}

void LinkedList::PushFront(Node* newNode) {
	//헤드뒤에 이미 노드가 있으면 임시저장
	Node* tempNode = NULL;
	if (headNode.nextNode != NULL) {
		tempNode = headNode.nextNode;
	}
	//새로운 노드를 헤드뒤에 연결뒤 임시저장노드 다시 연결
	headNode.nextNode = newNode;
	newNode->preNode = &headNode;
	//임시노드 새로운 노드와 전위연결
	newNode->nextNode = tempNode;
	if (tempNode != NULL) {
		tempNode->preNode = newNode;
	}
	//초기에 전위연결시 꼬리설정
	if (tailNode == &headNode)
	{
		tailNode = newNode;
	}
}

void LinkedList::PushBack(Node* newNode) {
	tailNode->nextNode = newNode;
	newNode->preNode = tailNode;
	tailNode = newNode;
}

void LinkedList::PrintNode() {
	Node* Node = headNode.nextNode;
	while (Node != nullptr) {
		cout << Node->id << "," << Node->value << " / ";
		Node = Node->nextNode;
	}
	cout << endl;
}

void LinkedList::DestroyNode() {
	Node* Node = headNode.nextNode;
	while (Node != nullptr) {
		Node = Node->nextNode;
		delete Node;
		Node = nullptr;
	}
}

void LinkedList::DeleteNode(Node* target) {
	target->preNode->nextNode = target->nextNode;
	target->nextNode->preNode = target->preNode;
	delete target;
	target = NULL;
}

void LinkedList::InsertNode(Node* targetNode, Node* newNode) {
	if (targetNode == NULL) {
		return;
	}
	if (headNode.nextNode == NULL) {
		headNode.nextNode = newNode;
		newNode->preNode = &headNode;
	}
	else {
		Node* temp_node = targetNode->nextNode;
		targetNode->nextNode = newNode;
		newNode->preNode = targetNode;
		newNode->nextNode = temp_node;
		if (temp_node != NULL) {
			temp_node->preNode = newNode;
		}
	}
}

void LinkedList::UpdateNode(Node* Node, int value) {
	Node->value = value;
}

void LinkedList::Save() {
	FILE* fp = NULL;
	//파일열기에 성공하면 0을 반환
	if (0 == fopen_s(&fp, "test.txt", "w")) {
		Node* Node = headNode.nextNode;
		while (Node != NULL) {
			fprintf(fp, "%d %d\n", Node->id, Node->value);
			Node = Node->nextNode;
		}
		fclose(fp);
	}
}

void LinkedList::Load() {
	FILE* fp = NULL;
	//파일열기에 성공하면 0을 반환
	if (0 == fopen_s(&fp, "test.txt", "r")) {
		//파일에 끝에 도달하면 1 반환s
		while (feof(fp) != 1) {
			Node* newNode = CreateNode(0, 0);
			fscanf_s(fp, "%d %d\n", &newNode->id, &newNode->value);
			PushBack(newNode);
		}
		fclose(fp);
	}
}