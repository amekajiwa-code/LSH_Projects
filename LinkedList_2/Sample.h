#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
//����� ���Ḯ��Ʈ
struct node {
	int id;
	int value;
	node* next_node;
	node* pre_node;
};

struct TMP {
	node* L1;
	node* L2;
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
void save(); // ����
void load(); // �ҷ�����
void init(); // �ʱⰪ

//����
node* merge(node* L1, node* L2);
//����
TMP partition(node* L, int k);
//����
void merge_sort(node** L, int k);

node* create_node() {
	node* new_node = (node*)malloc(sizeof(node));
	new_node->id = g_counter++;
	new_node->value = new_node->id * 10;
	new_node->next_node = NULL;
	return new_node;
}

void push_front(node* new_node) {
	//���ڿ� �̹� ��尡 ������ �ӽ�����
	node* temp_node = NULL;
	if (g_head_node.next_node != NULL) {
		temp_node = g_head_node.next_node;
	}
	//���ο� ��带 ���ڿ� ����� �ӽ������� �ٽ� ����
	g_head_node.next_node = new_node;
	new_node->pre_node = &g_head_node;
	//�ӽó�� ���ο� ���� ��������
	new_node->next_node = temp_node;
	if (temp_node != NULL) {
		temp_node->pre_node = new_node;
	}
	//�ʱ⿡ ��������� ��������
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
		cout << node->id << "," << node->value << " / ";
		node = node->next_node;
	}
	cout << endl;
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

void save() {
	FILE* fp = NULL;
	//���Ͽ��⿡ �����ϸ� 0�� ��ȯ
	if (0 == fopen_s(&fp, "test.txt", "w")) {
		node* node = g_head_node.next_node;
		while (node != NULL) {
			fprintf(fp, "%d %d\n", node->id, node->value);
			node = node->next_node;
		}
		fclose(fp);
	}
}

void load() {
	FILE* fp = NULL;
	//���Ͽ��⿡ �����ϸ� 0�� ��ȯ
	if (0 == fopen_s(&fp, "test.txt", "r")) {
		//���Ͽ� ���� �����ϸ� 1 ��ȯs
		while (feof(fp) != 1) {
			node* new_node = create_node();
			fscanf_s(fp, "%d %d\n", &new_node->id, &new_node->value);
			push_back(new_node);
		}
		fclose(fp);
	}
}

void init() {
	/*for (int i = 0; i < 5; ++i) {
		node* new_node = create_node();
		push_front(new_node);
	}*/

	for (int i = 0; i < 10; ++i) {
		node* new_node = create_node();
		push_back(new_node);
	}
}

//����
node* merge(node* L1, node* L2) {
	node* result = NULL;

	if (L1 == NULL) {
		return L2;
	}
	else if (L2 == NULL) {
		return L1;
	}

	//������������ ���� ���Ḯ��Ʈ�� ����������� ä��
	if (L1->value < L2->value) {
		result = L1;
		result->next_node = merge(L1->next_node, L2);
	}
	else {
		result = L2;
		result->next_node = merge(L1, L2->next_node);
	}
	return result;
}

TMP partition(node* L, int k) {
	TMP result;
	node* p = L;
	node* L1 = L;
	node* L2;

	for (int i = 0; i < k - 1; ++i) {
		p = p->next_node;
	}

	L2 = p->next_node;
	p->next_node = NULL;

	result.L1 = L1;
	result.L2 = L2;

	return result;
}

void merge_sort(node** L, int k) {
	node* L1 = NULL;
	node* L2 = NULL;
	TMP tmp;

	if (k > 1 && *L != NULL) {
		tmp = partition(*L, k / 2);
		L1 = tmp.L1;
		L2 = tmp.L2;

		merge_sort(&L1, k / 2);
		merge_sort(&L2, (int)((k / 2.0) + 0.5));
		*L = merge(L1, L2);
	}
}