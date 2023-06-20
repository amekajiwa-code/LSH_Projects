#pragma once
#include <iostream>

namespace Template {
	class node {
		int id;
		int value;
		node* next_node;
		node* pre_node;
	};

	node g_head_node;
	node* g_tail_node;
	int g_counter = 0;

	class LinkedList {

	public:
		LinkedList() {

		}
	private:

	};
}
