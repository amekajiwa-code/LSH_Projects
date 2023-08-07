#include "MyObject.h"

void MyObject::SetDirection(Vector3 target) {
    // ���� ��ġ���� ��ǥ ��ġ(target)������ ���� ���͸� ����մϴ�.
    mTarget = target;
    mDirection = mTarget - mPosition;

    // ���� ���͸� ����ȭ�Ͽ� ���̸� 1�� ����ϴ�. (���� ���ͷ� ��ȯ)
    mDirection.Normalize();
}

void MyObject::Move(float second) {
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