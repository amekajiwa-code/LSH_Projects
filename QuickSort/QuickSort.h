#pragma once

namespace Sort {
	class Node {
	public:
		int id;
		int value;
		Node* nextNode;
		Node* preNode;
	};

	class TMP {
	public:
		Node* L1;
		Node* L2;
	};

	class QuickSort {
	public:
		QuickSort();

		void QuickSortList(Node** L, int size) {
			QuickSortListRecursive(*L, *L, *L, size);
		}
	private:
		void QuickSortListRecursive(Node* L, Node* L1, Node* L2, int size) {
			
		}
		void partition();
		void swap();
	};
}
