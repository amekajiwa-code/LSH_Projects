#include <iostream>
#include "MyQuadrant.h"

using namespace std;

int main() {
	Vector3 frontTopLeft(0.0f, 0.0f, 0.0f);
	Vector3 backBottomRight(800.0f, 600.0f, 100.0f);
	double width = 800, height = 600, depth = 100;
	MyQuadrant* myTree = new MyQuadrant(frontTopLeft, backBottomRight, width, height, depth);

	myTree->BuildTree();

	delete myTree;
}