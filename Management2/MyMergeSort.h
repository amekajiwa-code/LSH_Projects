#pragma once
#include "MyLinkedList.h"

template<typename T>
struct TMP {
	Node<T>* L1;
	Node<T>* L2;
};

template<typename T>
class MergeSort {
public:
	void merge_sort(Node<T>** L, int k);
	TMP<T> partition(Node<T>* L, int k);
	Node<T>* merge(Node<T>* L1, Node<T>* L2);
private:
};

template<typename T>
void MergeSort<T>::merge_sort(Node<T>** L, int k) {
	Node<T>* L1 = nullptr;
	Node<T>* L2 = nullptr;
	TMP<T> tmp;

	if (k > 1 && *L != nullptr) {
		tmp = partition(*L, k / 2);
		L1 = tmp.L1;
		L2 = tmp.L2;

		merge_sort(&L1, k / 2);
		merge_sort(&L2, (k + 1) / 2);
		//merge_sort(&L2, (int)((k / 2.0) + 0.5));
		*L = merge(L1, L2);
	}
}

template<typename T>
TMP<T> MergeSort<T>::partition(Node<T>* L, int k) {
	TMP<T> result;
	Node<T>* p = L;
	Node<T>* L1 = L;
	Node<T>* L2;

	for (int i = 0; i < k - 1; ++i) {
		p = p->mNextNode;
	}

	L2 = p->mNextNode;
	p->mNextNode = nullptr;

	result.L1 = L1;
	result.L2 = L2;

	return result;
}

template<typename T>
Node<T>* MergeSort<T>::merge(Node<T>* L1, Node<T>* L2) {
	Node<T>* result = nullptr;

	if (L1 == nullptr) {
		return L2;
	}
	else if (L2 == nullptr) {
		return L1;
	}

	//오름차순으로 한쪽 연결리스트가 비워질때까지 채움
	if (L1->mNID < L2->mNID) {
		result = L1;
		result->mNextNode = merge(L1->mNextNode, L2);

	}
	else {
		result = L2;
		result->mNextNode = merge(L1, L2->mNextNode);
	}
	return result;
}