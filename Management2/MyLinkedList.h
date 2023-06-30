#pragma once

template<typename T>
class Node {
public:
	int mNID;
	T mData;
	Node* mNextNode;
	Node* mPreNode;
	Node() {
		mNID = -1;
		mNextNode = nullptr;
		mPreNode = nullptr;
	}
	Node(T data, int NID)
	{
		mNID = NID;
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
	MyLinkedList(const MyLinkedList& other);
	Node<T>* CreateNode(T data, int NID);
	Node<T>* FindNode(int id);
	void PushFront(Node<T>* newNode);
	void PushBack(Node<T>* newNode);
	//void PrintNode(); <-- Student Å¬·¡½º°¡ ±â´ÉÇÔ
	void DestroyNode();
	void DeleteNode(Node<T>* target);
	void InsertNode(Node<T>* targetNode, Node<T>* newNode);
	void UpdateNode(Node<T>* Node, T newData);
	int GetLength();
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
MyLinkedList<T>::MyLinkedList(const MyLinkedList<T>& other) {

}

template<typename T>
Node<T>* MyLinkedList<T>::CreateNode(T data, int NID) {
	Node<T>* newNode = new Node<T>(data, NID);
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
	if (mHeadNode.mNextNode == nullptr) {
		return;
	}
	Node<T>* node = mHeadNode.mNextNode;
	while (node != nullptr) {
		node = node->mNextNode;
		delete node;
		node = nullptr;
	}
	mHeadNode.mNextNode = nullptr;
	mHeadNode.mPreNode = nullptr;
	mTailNode = &mHeadNode;
};

template<typename T>
Node<T>* MyLinkedList<T>::FindNode(int id) {
	Node<T>* node = mHeadNode.mNextNode;
	while (node != nullptr) {
		if (node->mNID == id) {
			return node;
		}
		node = node->mNextNode;
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

template<typename T>
int MyLinkedList<T>::GetLength() {
	int length = 0;
	Node<T>* node = &mHeadNode;
	while (node != nullptr) {
		length++;
		node = node->mNextNode;
	}
	return length;
}