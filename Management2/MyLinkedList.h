#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
	T mData;
	Node* mNextNode;
	Node* mPreNode;
	Node() {
		mNextNode = nullptr;
		mPreNode = nullptr;
	}
	Node(T data)
	{
		mData = data;
		mNextNode = nullptr;
		mPreNode = nullptr;
	}
	virtual ~Node()
	{
	}
};

template<typename T>
class MyLinkedList {
public:
	MyLinkedList();
	~MyLinkedList();
	Node<T>* CreateNode(T data);
	//Node<T>* find_node(Nodt<T> data);
	//void PushFront(Node<T>* newNode);
	void PushBack(Node<T>* newNode);
	//void PrintNode();
	//void DestroyNode();
	//void DeleteNode(Node<T>* target);
	//void InsertNode(Node<T>* targetNode, Node<T>* newNode);
	//void UpdateNode(Node<T>* Node, int value);
	//¸â¹öº¯¼ö Ä¸½¶È­
	Node<T> mHeadNode;
	Node<T>* mTailNode;
private:

};

template<typename T>
MyLinkedList<T>::MyLinkedList() {
	mHeadNode.mNextNode = nullptr;
	mHeadNode.mPreNode = nullptr;
	mTailNode = &mHeadNode;
};

template<typename T>
MyLinkedList<T>::~MyLinkedList() {
	//void DestroyNode();
};

template<typename T>
Node<T>* MyLinkedList<T>::CreateNode(T data) {
	Node<T>* newNode = new Node<T>(data);
	return newNode;
};

template<typename T>
void MyLinkedList<T>::PushBack(Node<T>* newNode) {
	mTailNode->mNextNode = newNode;
	newNode->mPreNode = mTailNode;
	mTailNode = newNode;
};