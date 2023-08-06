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
        // ���� ��ġ���� ��ǥ ��ġ(target)������ ���� ���͸� ����մϴ�.
        mTarget = target;
        mDirection = mTarget - mPosition;

        // ���� ���͸� ����ȭ�Ͽ� ���̸� 1�� ����ϴ�. (���� ���ͷ� ��ȯ)
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

        // ȭ�� ��迡 �����ϸ� �̵� ������ �ݴ�� �ٲپ� �ݻ�ǵ��� �մϴ�.
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

    // MyObject�� Move �Լ��� �������̵��Ͽ� ������ �������� ����
    void Move(float second) override {
        Vector3 velocity = mDirection * speed * second;
        mPosition = mPosition + velocity;
        mObject.Set(mPosition, mObject.mWidth, mObject.mHeight, mObject.mDepth);

        // ȭ�� ��迡 �����ϸ� �̵� ������ �ݴ�� �ٲپ� �ݻ�ǵ��� �մϴ�.
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