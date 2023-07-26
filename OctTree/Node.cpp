#include "Node.h"

void Node::AddObject(Object* obj) {
	mObjectList.push_back(obj);
}

void Node::AddDynamicObject(Object* obj) {
	mDynamicObjectList.push_back(obj);
}

void Node::DelDynamicObject(Object* obj) {
	mDynamicObjectList.clear(); 
}

Node::Node() {
	mIndex = -1;
	mDepth = 0;
	mParent = nullptr;

	for (int i = 0; i < 8; ++i) {
		mChild[i] = nullptr;
	}

	for (std::list<Object*>::iterator iter = mObjectList.begin();
		iter != mObjectList.end();
		iter++) {
		Object* obj = *iter;
		delete obj;
	}
}

Node::Node(float x, float y, float z, float width, float height, float depth) : Node()
{

}

Node::~Node() {

}