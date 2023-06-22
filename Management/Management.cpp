﻿#include "Management.h"
//고쳐야될것 : 병합정렬 매개변수인자 오류 lvalue nextNode private로 감췄을때 오류 발생함
int main()
{
	LinkedList* list = new LinkedList();
	MergeSort ms;
	for (int i = 0; i < 10; ++i) {
		Node* newNode = list->CreateNode(i, i * 10);
		list->PushFront(newNode);
	}
	ms.merge_sort(&list->headNode.nextNode, 10);
	cout << list->headNode.GetNextNode()->GetId() << endl;
	//ms.merge_sort(&list->headNode.GetNextNode(), 10);
	list->PrintNode();
	list->Save();
	delete list;
	LinkedList* list2 = new LinkedList();
	list2->Load();
	list2->PrintNode();
	delete list2;
}

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
	//헤드뒤에 이미 노드가 있으면 임시저장
	Node* tempNode = nullptr;
	if (headNode.GetNextNode() != nullptr) {
		tempNode = headNode.GetNextNode();
	}
	//새로운 노드를 헤드뒤에 연결뒤 임시저장노드 다시 연결
	headNode.SetNextNode(newNode);
	newNode->SetPreNode(&headNode);
	//임시노드 새로운 노드와 전위연결
	newNode->SetNextNode(tempNode);
	if (tempNode != nullptr) {
		tempNode->SetPreNode(newNode);
	}
	//초기에 전위연결시 꼬리설정
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
	cout << "소멸자호출" << endl;
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

void LinkedList::Save() {
	ofstream fout;
	fout.open("savefile.txt");
	if (fout.is_open()) {
		Node* Node = headNode.GetNextNode();
		while (Node != nullptr) {
			fout << Node->GetId() << " " << Node->GetValue() << endl;
			Node = Node->GetNextNode();
		}
	}
	fout.close();
}

void LinkedList::Load() {
	ifstream fin;
	fin.open("savefile.txt");
	if (fin.is_open()) {
		int input;
		string trash;
		while (!fin.eof()) {
			Node* newNode = CreateNode(-1, -1);
			fin >> input;
			if (!fin.fail()) {
				newNode->SetId(input);
				fin >> input;
				if (!fin.fail()) {
					newNode->SetValue(input);
					PushBack(newNode);
					continue;
				}
			}
			fin.clear();
			fin >> trash;
		}
	}
	fin.close();
}