#pragma once
#include "GeometryUtils.h"

// 인터페이스를 정의하는 추상 클래스
class IMovable {
public:
	virtual void Move(float second) = 0; // 순수 가상 함수로 인터페이스 정의
	virtual ~IMovable() {}   // 가상 소멸자를 추가하여 추상 클래스로 만듦
};

class MyObject : public IMovable
{
public:
    float speed = 100.0f;
	Box mObject;
	Vector3 mPosition;
    Vector3 mTarget;
    Vector3 mDirection;
    

	MyObject(Box box, Vector3 pos) : mObject(box), mPosition(pos) {}

    void SetDirection(Vector3 target) {
        // 현재 위치에서 목표 위치(target)까지의 방향 벡터를 계산합니다.
        mTarget = target;
        mDirection = mTarget - mPosition;

        // 방향 벡터를 정규화하여 길이를 1로 만듭니다. (단위 벡터로 변환)
        mDirection.Normalize();
    }

	// IMovable 인터페이스의 Move 함수를 순수 가상 함수로 선언
	virtual void Move(float second) = 0;
};

class StaticObject : public MyObject {
public:
    StaticObject(Box box, Vector3 pos) : MyObject(box, pos) {}

    // MyObject의 Move 함수를 오버라이드하여 정적인 움직임을 구현
    virtual void Move(float second) override {
        // 정적인 움직임에 관한 구현
    }
};

class DynamicObject : public MyObject {
public:
    DynamicObject(Box box, Vector3 pos) : MyObject(box, pos) {}

    // MyObject의 Move 함수를 오버라이드하여 동적인 움직임을 구현
    virtual void Move(float second) override {
        Vector3 velocity = mDirection * speed * second;
        mPosition = mPosition + velocity;
        Vector3 sizeVec(mObject.mWidth, mObject.mHeight, mObject.mDepth);
        Vector3 endPosVec = mPosition + sizeVec;
        mObject.Set(mPosition, endPosVec, mObject.mWidth, mObject.mHeight, mObject.mDepth);

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