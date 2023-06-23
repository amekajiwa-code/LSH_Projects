#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"

class LinkedList {
public:
	LinkedList();
	~LinkedList();

	Node* CreateNode(int id, int value);
	Node* find_node(int id);
	void PushFront(Node* newNode);
	void PushBack(Node* newNode);
	void PrintNode();
	void DestroyNode();
	void DeleteNode(Node* target);
	void InsertNode(Node* targetNode, Node* newNode);
	void UpdateNode(Node* Node, int value);
	//���̺�,�ε� �и�
	void Save();
	void Load();
	//������� ĸ��ȭ
	Node headNode;
	Node* tailNode;
private:

};