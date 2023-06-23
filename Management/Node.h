#pragma once

class Node {
private:
	int id;
	int value;
public:
	Node* preNode;
	Node* nextNode;

	int GetId() const {
		return this->id;
	}
	int GetValue() const {
		return this->value;
	}
	Node* GetNextNode() const {
		return this->nextNode;
	}
	Node* GetPreNode() const {
		return this->preNode;
	}
	void SetId(int id) {
		this->id = id;
	}
	void SetValue(int value) {
		this->value = value;
	}
	void SetNextNode(Node* node) {
		this->nextNode = node;
	}
	void SetPreNode(Node* node) {
		this->preNode = node;
	}
};

struct TMP {
	Node* L1;
	Node* L2;
};