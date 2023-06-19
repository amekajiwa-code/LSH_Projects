﻿#include <iostream>
using namespace std;

//양방향 연결리스트
struct node	{
	int id;
	int value;
	node* next_node;
	node* pre_node;
};

node g_head_node;
node* g_tail_node;
int g_counter = 0;

node* create_node(); // 생성
void push_front(node* new_node); // 전위 연결
void push_back(node* new_node); // 후위 연결
void print_node(); // 출력
void destroy_node(); // 메모리 해제
node* find_node(int id); // 검색 -> 이분탐색으로 수정 이분탐색을 하려면 정렬을 해야한다
void delete_node(node* target); // 삭제 
bool insert_node(node* insert_node); // 삽입
void update_node(node* update_node, int value); //수정
//
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
	node* myNode = find_node(2);
	update_node(myNode, 99);
	insert_node(myNode);
	delete_node(myNode);
	print_node();
	destroy_node();
}

node* create_node() {
	node* new_node = (node*)malloc(sizeof(node));
	new_node->id = g_counter++;
	new_node->value = new_node->id * 10;
	new_node->next_node = NULL;
	return new_node;
}

void push_front(node* new_node) {
	//헤드뒤에 이미 노드가 있으면 임시저장
	node* temp_node = NULL;
	if (g_head_node.next_node != NULL) {
		temp_node = g_head_node.next_node;
	}
	//새로운 노드를 헤드뒤에 연결뒤 임시저장노드 다시 연결
	g_head_node.next_node = new_node;
	new_node->pre_node = &g_head_node;
	//임시노드 새로운 노드와 전위연결
	new_node->next_node = temp_node;
	if (temp_node != NULL) {
		temp_node->pre_node = new_node;
	}
	//초기에 전위연결시 꼬리설정
	if (g_tail_node == &g_head_node)
	{
		g_tail_node = new_node;
	}
}

void push_back(node* new_node) {
	g_tail_node->next_node = new_node;
	new_node->pre_node = g_tail_node;
	g_tail_node = new_node;
}

void print_node() {
	node* node = g_head_node.next_node;
	while (node != NULL) {
		cout << node->id << "," << node->value << " ";
		node = node->next_node;
	}
}

void destroy_node() {
	node* node = g_head_node.next_node;
	while (node != NULL) {
		node = node->next_node;
		free(node);
		node = NULL;
	}
}

node* find_node(int id) {
	node* node = g_head_node.next_node;
	while (node != NULL) {
		if (node->id == id) {
			return node;
		}
		node = node->next_node;
	}
	return NULL;
}

void delete_node(node* target) {
	target->pre_node->next_node = target->next_node;
	target->next_node->pre_node = target->pre_node;
	free(target);
	target = NULL;
}

bool insert_node(node* insert_node) {
	if (insert_node == NULL) {
		return false;
	}
	node* new_node = create_node();
	if (g_head_node.next_node == NULL) {
		g_head_node.next_node = new_node;
		new_node->pre_node = &g_head_node;
	}
	else {
		node* temp_node = insert_node->next_node;
		insert_node->next_node = new_node;
		new_node->pre_node = insert_node;
		new_node->next_node = temp_node;
		if (temp_node != NULL) {
			temp_node->pre_node = new_node;
		}
	}
	return true;
}

void update_node(node* node, int value) {
	node->value = value;
}