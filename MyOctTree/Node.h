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
		// ���� ����� �ڽ��� ������Ʈ�� �ڽ��� �浹�ϴ��� �˻�
		// �浹 ������ �����ؾ� �մϴ�. ���⼭�� AABB �浹 �׽�Ʈ�� ����մϴ�.
		if (mc.CheckCollision(obj.GetBox(), mBox)) {

			// ���� ����� �ڽ��� ������Ʈ�� �ڽ��� �浹�ϸ�
			// ����� �ڽ� ��忡 �߰��ϵ��� �մϴ�
			
			for (Node* child : mChildNodes) {
				if (mc.CheckCollision(obj.GetBox(), child->mBox)) {
					child->AddObject(obj);
					return;
				}
			}
		}
		else {
			// �浹���� ������ ������Ʈ�� mObjectList�� �߰��մϴ�.
			mObjectList.push_back(obj);
		}
	}
};

