#pragma once
#include "Object.h"
#include "Utils.h"

class Node
{
public:
	int mIndex;
	int mDepth;
	Node* mParent;
	std::vector<Node*> mChild;
	std::vector<Object*> mObjectList;
	std::vector<Object*> mDynamicObjectList;
};

