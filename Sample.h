#pragma
#include <iostream>
//양방향 연결리스트
struct node {
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