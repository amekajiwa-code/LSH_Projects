#pragma once
#include <vector>
#include "GeometryUtils.h"

class Node
{
public:
	int mId;
	int mDepth;
	Node* mParent = nullptr;
	std::vector<Node*> mChildNodes;
	Box mBox;

	Node() {
		mId = -1, mDepth = -1;
	};
	Node(Node* parent, Box box, int id) {
		mParent = parent;
		mId = id;
		mBox = box;
		if (parent != nullptr) {
			mDepth = parent->mDepth + 1;
		}
		else {
			mDepth = 0;
		}
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

