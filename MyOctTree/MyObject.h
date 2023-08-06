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

    void SetDirection(Vector3 target) {
        // 현재 위치에서 목표 위치(target)까지의 방향 벡터를 계산합니다.
        mTarget = target;
        mDirection = mTarget - mPosition;

        // 방향 벡터를 정규화하여 길이를 1로 만듭니다. (단위 벡터로 변환)
        mDirection.Normalize();
    }

    Box GetBox() {
        return mObject;
    }

    virtual void Move(float second) {
        if (mIsDynamic == false) return;

        Vector3 velocity = mDirection * speed * second;
        mPosition = mPosition + velocity;
        mObject.Set(mPosition, mObject.mWidth, mObject.mHeight, mObject.mDepth);

        // 화면 경계에 도달하면 이동 방향을 반대로 바꾸어 반사되도록 합니다.
        if (mPosition.mX < 0.0f || mPosition.mX > 800.0f) {
            mDirection.mX *= -1.0f;
        }
        if (mPosition.mY < 0.0f || mPosition.mY > 600.0f) {
            mDirection.mY *= -1.0f;
        }
        if (mPosition.mZ < 0.0f || mPosition.mZ > 100.0f) {
            mDirection.mZ *= -1.0f;
        }
    };
};

class DynamicObject : public MyObject {
public:
    DynamicObject(Box box, Vector3 pos, bool isDynamic) : MyObject(box, pos, isDynamic) {}

    // MyObject의 Move 함수를 오버라이드하여 동적인 움직임을 구현
    void Move(float second) override {
        Vector3 velocity = mDirection * speed * second;
        mPosition = mPosition + velocity;
        mObject.Set(mPosition, mObject.mWidth, mObject.mHeight, mObject.mDepth);

        // 화면 경계에 도달하면 이동 방향을 반대로 바꾸어 반사되도록 합니다.
        if (mPosition.mX < 0.0f || mPosition.mX > 800.0f) {
            mDirection.mX *= -1.0f;
        }
        if (mPosition.mY < 0.0f || mPosition.mY > 600.0f) {
            mDirection.mY *= -1.0f;
        }
        if (mPosition.mZ < 0.0f || mPosition.mZ > 100.0f) {
            mDirection.mZ *= -1.0f;
        }
    }
};