#pragma once
#include "Node.h"
#include <iostream>
#include <queue>
using namespace std;

class MyQuadrant
{
public:
	Node* rootNode = nullptr;
	Box* rootBox = nullptr;
	queue<Node*> nodeQueue;
	int id = -1;

	MyQuadrant() {};
	MyQuadrant(Vector3 frontTopLeft, Vector3 backBottomRight, double width, double height, double depth);
	~MyQuadrant() {
		//delete
		delete rootNode;
		delete rootBox;
	}

	void BuildTree();
private:
	void BuildTreeRecursive(Node* node);

	void ShowVector(Node* node);
};



