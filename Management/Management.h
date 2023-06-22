#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//DataStructure
struct Node {
	int id;
	int value;
	Node* nextNode;
	Node* preNode;
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
	void Save();
	void Load();

	Node headNode;
	Node* tailNode;
private:
	
};

class MergeSort {
public:
	void merge_sort(Node** L, int k) {
		Node* L1 = nullptr;
		Node* L2 = nullptr;
		TMP tmp;

		if (k > 1 && *L != nullptr) {
			tmp = partition(*L, k / 2);
			L1 = tmp.L1;
			L2 = tmp.L2;

			merge_sort(&L1, k / 2);
			merge_sort(&L2, (int)((k / 2.0) + 0.5));
			*L = merge(L1, L2);
		}
	}

	TMP partition(Node* L, int k) {
		TMP result;
		Node* p = L;
		Node* L1 = L;
		Node* L2;

		for (int i = 0; i < k - 1; ++i) {
			p = p->nextNode;
		}

		L2 = p->nextNode;
		p->nextNode = nullptr;

		result.L1 = L1;
		result.L2 = L2;

		return result;
	}

	Node* merge(Node* L1, Node* L2) {
		Node* result = nullptr;

		if (L1 == nullptr) {
			return L2;
		}
		else if (L2 == nullptr) {
			return L1;
		}

		//오름차순으로 한쪽 연결리스트가 비워질때까지 채움
		if (L1->value < L2->value) {
			result = L1;
			result->nextNode = merge(L1->nextNode, L2);
		}
		else {
			result = L2;
			result->nextNode = merge(L1, L2->nextNode);
		}
		return result;
	}
private:

};