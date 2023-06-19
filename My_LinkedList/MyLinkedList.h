#pragma once

class node {
	int id;
	int value;
	node* next_node;
	node* pre_node;
};

node g_head_node;
node* g_tail_node;
int g_counter = 0;

class MyLinkedList {

public:
	MyLinkedList() {

	}
private:

};