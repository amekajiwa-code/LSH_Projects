#pragma once
#include <vector>
#include "GeometryUtils.h"

class Node
{
public:
	int mId = -1;
	int mDepth = 0;
	Node* mParent = nullptr;
	std::vector<Node*> mChildNodes;
	Box mBox;

	Node() {};
	Node(Node* parent, Box box, int id) {
		mId = id;
		mParent = parent;
		mBox = box;
		mDepth = parent->mDepth++;
	};
	~Node() {
		//delete
		for (Node* child : mChildNodes) {
			delete child;
			child = nullptr;
		}
	}

	void AddChildNode(Node* node) {
		mChildNodes.push_back(node);
	}
};

