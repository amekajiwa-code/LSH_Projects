#pragma once
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include "Object.h"

class Node
{
public:
	int mIndex;
	int mDepth;
	Node* mParent;
	Node* mChild[8];
	std::list<Object*> mObjectList;
	std::list<Object*> mDynamicObjectList;

	Node();
	Node(float x, float y, float z, float width, float height, float depth);
	~Node();

	void AddObject(Object* obj);
	void AddDynamicObject(Object* obj);
	void DelDynamicObject(Object* obj);
};

