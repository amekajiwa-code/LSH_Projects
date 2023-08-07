#pragma once
#include <vector>
#include "MyObject.h"
#include "MyCollision.h"
#include <iostream>

class Node
{
public:
	int mId;
	int mDepth;
	Node* mParent = nullptr;
	std::vector<Node*> mChildNodes;
	Box mBox;
	std::vector<MyObject> mObjectList;
	MyCollision mc;

	Node() {
		mId = -1, mDepth = -1;
	};
	Node(Node* parent, Box box, int id);
	~Node();

	void AddChildNode(Node* node);

	void AddObject(MyObject obj);
};

