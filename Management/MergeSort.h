#pragma once
#include "Node.h"

class MergeSort {
public:
	void merge_sort(Node** L, int k);
	TMP partition(Node* L, int k);
	Node* merge(Node* L1, Node* L2);
private:
};