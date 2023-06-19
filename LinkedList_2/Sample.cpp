#include "Sample.h"

int main() {
	g_head_node.id = -1;
	g_head_node.value = -1;
	g_head_node.pre_node = NULL;
	g_head_node.next_node = NULL;
	g_tail_node = &g_head_node;


	for (int i = 0; i < 5; ++i) {
		node* new_node = create_node();
		push_front(new_node);
	}
	for (int i = 0; i < 5; ++i) {
		node* new_node = create_node();
		push_back(new_node);
	}
	//node* myNode = find_node(2);
	//update_node(myNode, 99);
	//insert_node(myNode);
	//delete_node(myNode);
	print_node();
	destroy_node();
}