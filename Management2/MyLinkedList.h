#pragma once

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
	Node<T>* FindNode(const T& searchData);
	void PushFront(Node<T>* newNode);
	void PushBack(Node<T>* newNode);
	//void PrintNode(); <-- Student Å¬·¡½º°¡ ±â´ÉÇÔ
	void DestroyNode();
	void DeleteNode(Node<T>* target);
	void InsertNode(Node<T>* targetNode, Node<T>* newNode);
	void UpdateNode(Node<T>* Node, T newData);
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
	void DestroyNode();
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

template<typename T>
void MyLinkedList<T>::PushFront(Node<T>* newNode) {
	Node<T>* tempNode = nullptr;
	if (mHeadNode.mNextNode != nullptr) {
		tempNode = mHeadNode.mNextNode;
	}

	mHeadNode.mNextNode = newNode;
	newNode->mPreNode = &mHeadNode;

	newNode->mNextNode = tempNode;
	if (tempNode != nullptr) {
		tempNode->mPreNode = newNode;
	}

	if (mTailNode == &mHeadNode)
	{
		mTailNode = newNode;
	}
};

template<typename T>
void MyLinkedList<T>::DestroyNode() {
	Node<T>* node = mHeadNode.mNextNode;
	while (node != nullptr) {
		node = node->mNextNode;
		delete node;
		node = nullptr;
	}
};

template<typename T>
Node<T>* MyLinkedList<T>::FindNode(const T& searchData) {
	Node<T>* node = mHeadNode.mNextNode;
	while (node != nullptr) {
		if (node->mData == searchData) {
			return node;
		}
		node = nullptr;
	}
	return nullptr;
};

template<typename T>
void MyLinkedList<T>::DeleteNode(Node<T>* target) {
	target->mPreNode->mNextNode = target->mNextNode;
	target->mNextNode->mPreNode = target->mPreNode;
	delete target;
	target = nullptr;
};

template<typename T>
void MyLinkedList<T>::InsertNode(Node<T>* targetNode, Node<T>* newNode) {
	if (targetNode == nullptr) {
		return;
	}
	if (mHeadNode.mNextNode == nullptr) {
		mHeadNode.mNextNode = newNode;
		newNode->mPreNode = &mHeadNode;
	}
	else {
		Node<T>* tempNode = targetNode->mNextNode;
		targetNode->mNextNode = newNode;
		newNode->mPreNode = targetNode;
		newNode->mNextNode = tempNode;
		if (tempNode != nullptr) {
			tempNode->mPreNode = newNode;
		}
	}
};

template<typename T>
void MyLinkedList<T>::UpdateNode(Node<T>* node, T newData) {
	node->mData = newData;
};