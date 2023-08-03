#pragma once
#include <vector>
#include "MyObject.h"
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

	bool CheckCollision(const Box& box1, const Box& box2) {
		// 두 박스의 최소점과 최대점 좌표를 가져옵니다.
		Vector3 minPoint1 = box1.mFrontTopLeft;
		Vector3 maxPoint1 = box1.mBackBottomRight;
		Vector3 minPoint2 = box2.mFrontTopLeft;
		Vector3 maxPoint2 = box2.mBackBottomRight;

		// 두 박스가 충돌하는지 여부를 검사합니다.
		if (minPoint1.getX() <= maxPoint2.getX() && maxPoint1.getX() >= minPoint2.getX() &&
			minPoint1.getY() <= maxPoint2.getY() && maxPoint1.getY() >= minPoint2.getY() &&
			minPoint1.getZ() <= maxPoint2.getZ() && maxPoint1.getZ() >= minPoint2.getZ()) {
			// 두 박스가 충돌하면 true를 반환합니다.
			return true;
		}

		// 두 박스가 충돌하지 않으면 false를 반환합니다.
		return false;
	}

	void AddChildNode(Node* node) {
		mChildNodes.push_back(node);
	}

	void AddObject(MyObject obj) {
		// 현재 노드의 박스와 오브젝트의 박스가 충돌하는지 검사
		// 충돌 조건을 설정해야 합니다. 여기서는 AABB 충돌 테스트를 사용합니다.
		if (CheckCollision(obj.GetBox(), mBox)) {

			// 현재 노드의 박스와 오브젝트의 박스가 충돌하면
			// 노드의 자식 노드에 추가하도록 합니다.
			for (Node* child : mChildNodes) {
				child->AddObject(obj);
				return;
			}
		}
		else {
			// 충돌하지 않으면 오브젝트를 mObjectList에 추가합니다.

			std::cout << "노드ID : " << mId << " / 오브젝트 크기: " << obj.GetBox().mWidth << ", " << obj.GetBox().mHeight << std::endl;
			mObjectList.push_back(obj);
		}
	}
};

