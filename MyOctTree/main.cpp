#include <iostream>
#include "MyQuadrant.h"
#include "Timer.h"

using namespace std;

MyObject CreateObject() {
    const int numObjects = 10;
    const int maxCoordX = 800;
    const int maxCoordY = 600;
    const int maxCoordZ = 100;

    double randX = static_cast<double>(std::rand() % (maxCoordX));
    double randY = static_cast<double>(std::rand() % (maxCoordY));
    double randZ = static_cast<double>(std::rand() % (maxCoordZ));

    Vector3 randPos(randX, randY, randZ);
    Box randBox(randPos, Vector3(randX + 10, randY + 10, randZ + 10), 10, 10, 10);

    return MyObject(randBox, randPos, false);
}

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

    return DynamicObject(randBox, randPos, true);
}

int main() {
	Vector3 frontTopLeft(0.0f, 0.0f, 0.0f);
	Vector3 backBottomRight(800.0f, 600.0f, 100.0f);
	double width = 800, height = 600, depth = 100;
	MyQuadrant* myTree = new MyQuadrant(frontTopLeft, backBottomRight, width, height, depth);
    vector<MyObject> objList;
    MyCollision myCollision;

	myTree->BuildTree();

    for (int i = 0; i < 8; ++i) {
        Vector3 target(0, 0, 0);

        MyObject obj = DynamicCreateObject();
        obj.SetDirection(target);

        MyObject obj2 = CreateObject();
        obj2.SetDirection(target);

        myTree->rootNode->AddObject(obj);
        myTree->rootNode->AddObject(obj2);
        objList.push_back(obj);
        objList.push_back(obj2);
    }

    Timer timer;
    timer.Init();

    while (true) {
        timer.Frame();

        //for (DynamicObject& obj : dynamicObjList) {
        //    obj.Move(timer.mSecondPerFrame);
        //    for (DynamicObject& obj2 : dynamicObjList) {
        //        if (obj.GetBox().mFrontTopLeft == obj2.GetBox().mFrontTopLeft) {
        //            continue;
        //        }

        //        if (myCollision.CheckCollision(obj.GetBox(), obj2.GetBox())) {
        //            //obj와 obj2 dynamicObjList에서 삭제
        //        }
        //    }
        //}

        for (auto it = objList.begin(); it != objList.end(); ) {
            MyObject& obj = *it;
            obj.Move(timer.mSecondPerFrame);

            bool shouldDelete = false;
            for (auto it2 = objList.begin(); it2 != objList.end(); ++it2) {
                if (it == it2) {
                    continue;
                }

                MyObject& obj2 = *it2;

                if (myCollision.CheckCollision(obj.GetBox(), obj2.GetBox())) {
                    shouldDelete = true;
                    break;
                }
            }

            if (shouldDelete) {
                it = objList.erase(it);
            }
            else {
                ++it;
            }
        }

        system("cls");
        timer.Render();

        int index = 0;
            for (MyObject& obj : objList) {
                cout << "[" << index++ << "] " << "( " << obj.mPosition.getX() <<
                    ", " << obj.mPosition.getY()
                    << ", " << obj.mPosition.getZ() << ", )" << endl;
            }

        Sleep(300);            
    }

	delete myTree;
}