#pragma
#include <iostream>
//����� ���Ḯ��Ʈ
struct node {
	int id;
	int value;
	node* next_node;
	node* pre_node;
};

node g_head_node;
node* g_tail_node;
int g_counter = 0;

node* create_node(); // ����
void push_front(node* new_node); // ���� ����
void push_back(node* new_node); // ���� ����
void print_node(); // ���
void destroy_node(); // �޸� ����
node* find_node(int id); // �˻� -> �̺�Ž������ ���� �̺�Ž���� �Ϸ��� ������ �ؾ��Ѵ�
void delete_node(node* target); // ���� 
bool insert_node(node* insert_node); // ����
void update_node(node* update_node, int value); //����