#pragma once
#include "Point.h"
#include <cmath>

class Rect
{
private:
	Point mTopLeft;
	Point mBottomRight;
public:
	//�����ڷ� mTopLeft, mBottomRight �ʱ�ȭ
	Rect(Point topLeft, int width, int height) 
		: mTopLeft(topLeft), mBottomRight(topLeft.GetX() + width, topLeft.GetY() + height)
	{
	}

	int GetWidth() {
		int x1 = mTopLeft.GetX();
		int x2 = mBottomRight.GetX();

		return abs(x1 - x2);
	}

	int GetHeight() {
		int y1 = mTopLeft.GetY();
		int y2 = mBottomRight.GetY();

		return abs(y1 - y2);
	}

	Point GetTopLeft() {
		return mTopLeft;
	}

	Point GetBottomRight() {
		return mBottomRight;
	}
	
	// ���� �簢���� ���ԵǴ��� Ȯ��
	bool contains(Point point) {
		int pX = point.GetX();
		int pY = point.GetY();

		//���� ��ǥ�� x���� �»�� x���� ũ�ų� ���ų�
		//���� ��ǥ�� x���� ���ϴ� x���� �۰ų� ���ų�
		//���� ��ǥ�� y���� �»�� y���� ũ�ų� ���ų�
		//���� ��ǥ�� y���� ���ϴ� x���� �۰ų� ���ų�
		return pX >= mTopLeft.GetX()
			&& pX <= mBottomRight.GetX()
			&& pY >= mTopLeft.GetY()
			&& pY <= mBottomRight.GetY();
	}

	// �ٸ� �簢���� �簢���� ���ԵǴ��� Ȯ��
	bool contains(Rect other) {
		int x1 = mTopLeft.GetX();
		int x2 = mBottomRight.GetX();
		int y1 = mTopLeft.GetY();
		int y2 = mBottomRight.GetY();

		int otherX1 = other.mTopLeft.GetX();
		int otherX2 = other.mBottomRight.GetX();
		int otherY1 = other.mTopLeft.GetY();
		int otherY2 = other.mBottomRight.GetY();

		//�ٸ� �簢���� �»�� ��ǥ���� this�簢������ ũ�ų� ����
		//���ϴ� ��ǥ���� this�簢������ �۰ų� ������ ����
		return x1 <= otherX1
			&& x2 >= otherX2
			&& y1 <= otherY1
			&& y2 >= otherY2;
	}
};

