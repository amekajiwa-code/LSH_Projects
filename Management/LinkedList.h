#pragma once
#include <iostream>
#include <fstream>
#include <string>

#pragma once

class Node {
private:
	int id;
	int value;
public:
	Node* preNode;
	Node* nextNode;

	int GetId() const {
		return this->id;
	}
	int GetValue() const {
		return this->value;
	}
	Node* GetNextNode() const {
		return this->nextNode;
	}
	Node* GetPreNode() const {
		return this->preNode;
	}
	void SetId(int id) {
		this->id = id;
	}
	void SetValue(int value) {
		this->value = value;
	}
	void SetNextNode(Node* node) {
		this->nextNode = node;
	}
	void SetPreNode(Node* node) {
		this->preNode = node;
	}
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