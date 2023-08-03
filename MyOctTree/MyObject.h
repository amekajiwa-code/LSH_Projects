#pragma once
#include "GeometryUtils.h"

// �������̽��� �����ϴ� �߻� Ŭ����
class IMovable {
public:
	virtual void Move(float second) = 0; // ���� ���� �Լ��� �������̽� ����
	virtual ~IMovable() {}   // ���� �Ҹ��ڸ� �߰��Ͽ� �߻� Ŭ������ ����
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
        // ���� ��ġ���� ��ǥ ��ġ(target)������ ���� ���͸� ����մϴ�.
        mTarget = target;
        mDirection = mTarget - mPosition;

        // ���� ���͸� ����ȭ�Ͽ� ���̸� 1�� ����ϴ�. (���� ���ͷ� ��ȯ)
        mDirection.Normalize();
    }

	// IMovable �������̽��� Move �Լ��� ���� ���� �Լ��� ����
	virtual void Move(float second) = 0;
};

class StaticObject : public MyObject {
public:
    StaticObject(Box box, Vector3 pos) : MyObject(box, pos) {}

    // MyObject�� Move �Լ��� �������̵��Ͽ� ������ �������� ����
    virtual void Move(float second) override {
        // ������ �����ӿ� ���� ����
    }
};

class DynamicObject : public MyObject {
public:
    DynamicObject(Box box, Vector3 pos) : MyObject(box, pos) {}

    // MyObject�� Move �Լ��� �������̵��Ͽ� ������ �������� ����
    virtual void Move(float second) override {
        Vector3 velocity = mDirection * speed * second;
        mPosition = mPosition + velocity;
        Vector3 sizeVec(mObject.mWidth, mObject.mHeight, mObject.mDepth);
        Vector3 endPosVec = mPosition + sizeVec;
        mObject.Set(mPosition, endPosVec, mObject.mWidth, mObject.mHeight, mObject.mDepth);

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