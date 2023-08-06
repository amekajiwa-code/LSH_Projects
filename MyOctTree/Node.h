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

	void AddObject(MyObject obj) {
		// 현재 노드의 박스와 오브젝트의 박스가 충돌하는지 검사
		// 충돌 조건을 설정해야 합니다. 여기서는 AABB 충돌 테스트를 사용합니다.
		if (mc.CheckCollision(obj.GetBox(), mBox)) {

			// 현재 노드의 박스와 오브젝트의 박스가 충돌하면
			// 노드의 자식 노드에 추가하도록 합니다
			
			for (Node* child : mChildNodes) {
				if (mc.CheckCollision(obj.GetBox(), child->mBox)) {
					child->AddObject(obj);
					return;
				}
			}
		}
		else {
			// 충돌하지 않으면 오브젝트를 mObjectList에 추가합니다.
			mObjectList.push_back(obj);
		}
	}
};

