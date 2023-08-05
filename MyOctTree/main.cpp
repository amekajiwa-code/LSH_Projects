#include <iostream>
#include "MyQuadrant.h"
#include "Timer.h"

using namespace std;

DynamicObject DynamicCreateObject() {
    const int numObjects = 10;
    const int maxCoordX = 800;
    const int maxCoordY = 600;
    const int maxCoordZ = 100;

    double randX = static_cast<double>(std::rand() % (maxCoordX));
    double randY = static_cast<double>(std::rand() % (maxCoordY));
    double randZ = static_cast<double>(std::rand() % (maxCoordZ));

    Vector3 randPos(randX, randY, randZ);
    Box randBox(randPos, Vector3(randX + 10, randY + 10, randZ + 10), 10, 10, 10);

    return DynamicObject(randBox, randPos);
}

int main() {
	Vector3 frontTopLeft(0.0f, 0.0f, 0.0f);
	Vector3 backBottomRight(800.0f, 600.0f, 100.0f);
	double width = 800, height = 600, depth = 100;
	MyQuadrant* myTree = new MyQuadrant(frontTopLeft, backBottomRight, width, height, depth);
    vector<DynamicObject> dynamicObjList;

	myTree->BuildTree();

    for (int i = 0; i < 8; ++i) {
        DynamicObject obj = DynamicCreateObject();
        Vector3 target(0, 0, 0);
        obj.SetDirection(target);
        myTree->rootNode->AddObject(obj);
        dynamicObjList.push_back(obj);
    }

    Timer timer;
    timer.Init();

    while (true) {
        timer.Frame();

        for (DynamicObject& obj : dynamicObjList) {
            obj.Move(timer.mSecondPerFrame);
        }

        system("cls");
        timer.Render();

        int index = 0;
            for (DynamicObject& obj : dynamicObjList) {
                cout << "[" << index++ << "] " << "( " << obj.mPosition.getX() <<
                    ", " << obj.mPosition.getY()
                    << ", " << obj.mPosition.getZ() << ", )" << endl;
            }
        

        Sleep(500);
    }

	delete myTree;
}