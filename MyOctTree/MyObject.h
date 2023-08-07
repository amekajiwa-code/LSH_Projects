#pragma once
#include "GeometryUtils.h"

class MyObject
{
public:
    float speed = 100.0f;
	Box mObject;
	Vector3 mPosition;
    Vector3 mTarget;
    Vector3 mDirection;
    bool mIsDynamic;
    

	MyObject(Box box, Vector3 pos, bool isDynamic) : mObject(box), mPosition(pos), mIsDynamic(isDynamic) {}

    void SetDirection(Vector3 target);

    Box GetBox() {
        return mObject;
    }

    void Move(float second);
};

class DynamicObject : public MyObject {
public:
    DynamicObject(Box box, Vector3 pos, bool isDynamic) : MyObject(box, pos, isDynamic) {}
};