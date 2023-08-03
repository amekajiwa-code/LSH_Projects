#pragma once
#include "Node.h"
#include <iostream>
#include <queue>
using namespace std;

class MyQuadrant
{
public:
	Node* rootNode = nullptr;
	Box* rootBox = nullptr;
	queue<Node*> nodeQueue;
	int id = -1;

	MyQuadrant() {};
	MyQuadrant(Vector3 frontTopLeft, Vector3 backBottomRight, double width, double height, double depth) {
		rootBox = new Box(frontTopLeft, backBottomRight, width, height, depth);
		rootNode = new Node(nullptr, *rootBox, ++id);
	};
	~MyQuadrant() {
		//delete
		delete rootNode;
		delete rootBox;
	}

	void BuildTree() {
		if (rootNode == nullptr) {
			cout << "No root node exists." << endl;
			return;
		}

		nodeQueue.push(rootNode);

		BuildTreeRecursive(rootNode);
		//레벨 순회
		while (!nodeQueue.empty()) {
			Node* currentNode = nodeQueue.front();
			nodeQueue.pop();

			// Process the current node (show its vector)
			//ShowVector(currentNode);

			// Add child nodes to the queue
			for (int i = 0; i < currentNode->mChildNodes.size(); i++) {
				nodeQueue.push(currentNode->mChildNodes[i]);
			}
		}
	}
private:
	void BuildTreeRecursive(Node* node) {
		if (node->mDepth > 1) {
			return;
		}

		double halfW = node->mBox.mWidth / 2;
		double halfH = node->mBox.mHeight / 2;
		double halfD = node->mBox.mDepth / 2;
		Vector3 originVec = node->mBox.mFrontTopLeft;
		Vector3 halfVec(halfW, halfH, halfD);

		//0
		Vector3 startVec0 = originVec;
		Vector3 endVec0 = originVec + halfVec;
		Box box0(startVec0, endVec0, halfW, halfH, halfD);
		Node* node0 = new Node(node, box0, ++id);
		node->AddChildNode(node0);
		//1
		Vector3 sumVec1(halfW, 0, 0);
		Vector3 startVec1 = originVec + sumVec1;
		Vector3 endVec1 = startVec1 + halfVec;
		Box box1(startVec1, endVec1, halfW, halfH, halfD);
		Node* node1 = new Node(node, box1, ++id);
		node->AddChildNode(node1);
		//2
		Vector3 sumVec2(0, halfH, 0);
		Vector3 startVec2 = originVec + sumVec2;
		Vector3 endVec2 = startVec2 + halfVec;
		Box box2(startVec2, endVec2, halfW, halfH, halfD);
		Node* node2 = new Node(node, box2, ++id);
		node->AddChildNode(node2);
		//3
		Vector3 sumVec3(halfW, halfH, 0);
		Vector3 startVec3 = originVec + sumVec3;
		Vector3 endVec3 = startVec3 + halfVec;
		Box box3(startVec3, endVec3, halfW, halfH, halfD);
		Node* node3 = new Node(node, box3, ++id);
		node->AddChildNode(node3);
		//4
		Vector3 sumVec4(0, 0, halfD);
		Vector3 startVec4 = originVec + sumVec4;
		Vector3 endVec4 = originVec + halfVec;
		Box box4(startVec4, endVec4, halfW, halfH, halfD);
		Node* node4 = new Node(node, box4, ++id);
		node->AddChildNode(node4);
		//5
		Vector3 sumVec5(halfW, 0, halfD);
		Vector3 startVec5 = originVec + sumVec5;
		Vector3 endVec5 = startVec5 + halfVec;
		Box box5(startVec5, endVec5, halfW, halfH, halfD);
		Node* node5 = new Node(node, box5, ++id);
		node->AddChildNode(node5);
		//6
		Vector3 sumVec6(0, halfH, halfD);
		Vector3 startVec6 = originVec + sumVec6;
		Vector3 endVec6 = startVec6 + halfVec;
		Box box6(startVec6, endVec6, halfW, halfH, halfD);
		Node* node6 = new Node(node, box6, ++id);
		node->AddChildNode(node6);
		//7
		Vector3 sumVec7(halfW, halfH, halfD);
		Vector3 startVec7 = originVec + sumVec7;
		Vector3 endVec7 = startVec7 + halfVec;
		Box box7(startVec7, endVec7, halfW, halfH, halfD);
		Node* node7 = new Node(node, box7, ++id);
		node->AddChildNode(node7);

		//전위순회
		//ShowVector(node);
		for (int i = 0; i < node->mChildNodes.size(); i++)
		{
			BuildTreeRecursive(node->mChildNodes[i]);
		}
	}

	void ShowVector(Node* node) {
		cout << "깊이 : " << node->mDepth << endl;
		cout << "벡터 : " << node->mBox.mFrontTopLeft.getX() << ", "
			<< node->mBox.mFrontTopLeft.getY() << ", " <<
			node->mBox.mFrontTopLeft.getZ() << endl;
	}
};



