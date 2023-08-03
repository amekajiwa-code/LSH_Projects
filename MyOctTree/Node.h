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
		// �� �ڽ��� �ּ����� �ִ��� ��ǥ�� �����ɴϴ�.
		Vector3 minPoint1 = box1.mFrontTopLeft;
		Vector3 maxPoint1 = box1.mBackBottomRight;
		Vector3 minPoint2 = box2.mFrontTopLeft;
		Vector3 maxPoint2 = box2.mBackBottomRight;

		// �� �ڽ��� �浹�ϴ��� ���θ� �˻��մϴ�.
		if (minPoint1.getX() <= maxPoint2.getX() && maxPoint1.getX() >= minPoint2.getX() &&
			minPoint1.getY() <= maxPoint2.getY() && maxPoint1.getY() >= minPoint2.getY() &&
			minPoint1.getZ() <= maxPoint2.getZ() && maxPoint1.getZ() >= minPoint2.getZ()) {
			// �� �ڽ��� �浹�ϸ� true�� ��ȯ�մϴ�.
			return true;
		}

		// �� �ڽ��� �浹���� ������ false�� ��ȯ�մϴ�.
		return false;
	}

	void AddChildNode(Node* node) {
		mChildNodes.push_back(node);
	}

	void AddObject(MyObject obj) {
		// ���� ����� �ڽ��� ������Ʈ�� �ڽ��� �浹�ϴ��� �˻�
		// �浹 ������ �����ؾ� �մϴ�. ���⼭�� AABB �浹 �׽�Ʈ�� ����մϴ�.
		if (CheckCollision(obj.GetBox(), mBox)) {

			// ���� ����� �ڽ��� ������Ʈ�� �ڽ��� �浹�ϸ�
			// ����� �ڽ� ��忡 �߰��ϵ��� �մϴ�.
			for (Node* child : mChildNodes) {
				child->AddObject(obj);
				return;
			}
		}
		else {
			// �浹���� ������ ������Ʈ�� mObjectList�� �߰��մϴ�.

			std::cout << "���ID : " << mId << " / ������Ʈ ũ��: " << obj.GetBox().mWidth << ", " << obj.GetBox().mHeight << std::endl;
			mObjectList.push_back(obj);
		}
	}
};

