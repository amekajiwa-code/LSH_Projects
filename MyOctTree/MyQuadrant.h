#pragma once
#include "Node.h"

class MyQuadrant
{
public:
	Node* rootNode = nullptr;
	Box* rootBox = nullptr;
	int id = -1;

	MyQuadrant() {};
	MyQuadrant(Vector3 frontTopLeft, Vector3 backBottomRight, double width, double height, double depth) {
		rootBox = new Box(frontTopLeft, backBottomRight, width, height, depth);
		rootNode = new Node(nullptr, rootBox, ++id);
	};
	~MyQuadrant() {
		//delete
		delete rootNode;
		delete rootBox;
	}

	void BuildTreeRecursive(Node* node) {
		if (node->mDepth > 1) {
			return;
		}
		//0
		//1
		//2
		//3
		//4
		//5
		//6
		//7
		for (int i = 0; i < node->mChildNodes.size(); i++)
		{
			BuildTreeRecursive(node->mChildNodes[i]);
		}
		
	}
};



