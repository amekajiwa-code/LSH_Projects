#include "MergeSort.h"

void MergeSort::merge_sort(Node** L, int k) {
	Node* L1 = nullptr;
	Node* L2 = nullptr;
	TMP tmp;

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

TMP MergeSort::partition(Node* L, int k) {
	TMP result;
	Node* p = L;
	Node* L1 = L;
	Node* L2;

	for (int i = 0; i < k - 1; ++i) {
		p = p->GetNextNode();
	}

	L2 = p->GetNextNode();
	p->SetNextNode(nullptr);

	result.L1 = L1;
	result.L2 = L2;

	return result;
}

Node* MergeSort::merge(Node* L1, Node* L2) {
	Node* result = nullptr;

	if (L1 == nullptr) {
		return L2;
	}
	else if (L2 == nullptr) {
		return L1;
	}

	//오름차순으로 한쪽 연결리스트가 비워질때까지 채움
	if (L1->GetValue() < L2->GetValue()) {
		result = L1;
		result->SetNextNode(merge(L1->GetNextNode(), L2));
	}
	else {
		result = L2;
		result->SetNextNode(merge(L1, L2->GetNextNode()));
	}
	return result;
}