#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
	headNode.SetId(-1);
	headNode.SetValue(-1);
	headNode.SetNextNode(nullptr);
	headNode.SetPreNode(nullptr);
	tailNode = &headNode;
}

LinkedList::~LinkedList()
{
	DestroyNode();
}

Node* LinkedList::CreateNode(int id, int value) {
	Node* newNode = new Node;
	newNode->SetId(id);
	newNode->SetValue(value);
	newNode->SetNextNode(nullptr);
	newNode->SetPreNode(nullptr);
	return newNode;
}

Node* LinkedList::find_node(int id) {
	Node* Node = headNode.GetNextNode();
	while (Node != nullptr) {
		if (Node->GetId() == id) {
			return Node;
		}
		Node = Node->GetNextNode();
	}
	return nullptr;
}

void LinkedList::PushFront(Node* newNode) {
	//���ڿ� �̹� ��尡 ������ �ӽ�����
	Node* tempNode = nullptr;
	if (headNode.GetNextNode() != nullptr) {
		tempNode = headNode.GetNextNode();
	}
	//���ο� ��带 ���ڿ� ����� �ӽ������� �ٽ� ����
	headNode.SetNextNode(newNode);
	newNode->SetPreNode(&headNode);
	//�ӽó�� ���ο� ���� ��������
	newNode->SetNextNode(tempNode);
	if (tempNode != nullptr) {
		tempNode->SetPreNode(newNode);
	}
	//�ʱ⿡ ��������� ��������
	if (tailNode == &headNode)
	{
		tailNode = newNode;
	}
}

void LinkedList::PushBack(Node* newNode) {
	tailNode->SetNextNode(newNode);
	newNode->SetPreNode(tailNode);
	tailNode = newNode;
}

void LinkedList::PrintNode() {
	Node* Node = headNode.GetNextNode();
	while (Node != nullptr) {
		cout << Node->GetId() << "," << Node->GetValue() << " / ";
		Node = Node->GetNextNode();
	}
	cout << endl;
}

void LinkedList::DestroyNode() {
	Node* Node = headNode.GetNextNode();
	while (Node != nullptr) {
		Node = Node->GetNextNode();
		delete Node;
		Node = nullptr;
	}
}

void LinkedList::DeleteNode(Node* target) {
	target->GetPreNode()->SetNextNode(target->GetNextNode());
	target->GetNextNode()->SetPreNode(target->GetPreNode());
	delete target;
	target = nullptr;
}

void LinkedList::InsertNode(Node* targetNode, Node* newNode) {
	if (targetNode == nullptr) {
		return;
	}
	if (headNode.GetNextNode() == nullptr) {
		headNode.SetNextNode(newNode);
		newNode->SetPreNode(&headNode);
	}
	else {
		Node* temp_node = targetNode->GetNextNode();
		targetNode->SetNextNode(newNode);
		newNode->SetPreNode(targetNode);
		newNode->SetNextNode(temp_node);
		if (temp_node != nullptr) {
			temp_node->SetPreNode(newNode);
		}
	}
}

void LinkedList::UpdateNode(Node* Node, int value) {
	Node->SetValue(value);
}