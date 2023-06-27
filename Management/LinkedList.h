#pragma once
#include <iostream>

class Node {
	int id;
	int value;
	Node* preNode;
	Node* nextNode;
};

struct TMP {
	Node* L1;
	Node* L2;
};

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
	//¸â¹öº¯¼ö Ä¸½¶È­
	Node headNode;
	Node* tailNode;
private:

};