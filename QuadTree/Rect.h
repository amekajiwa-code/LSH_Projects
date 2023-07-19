#pragma once
#include "Point.h"
#include <cmath>

class Rect
{
private:
	Point mTopLeft;
	Point mBottomRight;
public:
	//생성자로 mTopLeft, mBottomRight 초기화
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
	
	// 점이 사각형에 포함되는지 확인
	bool contains(Point point) {
		int pX = point.GetX();
		int pY = point.GetY();

		//받은 좌표의 x값이 좌상단 x보다 크거나 같거나
		//받은 좌표의 x값이 우하단 x보다 작거나 같거나
		//받은 좌표의 y값이 좌상단 y보다 크거나 같거나
		//받은 좌표의 y값이 우하단 x보다 작거나 같거나
		return pX >= mTopLeft.GetX()
			&& pX <= mBottomRight.GetX()
			&& pY >= mTopLeft.GetY()
			&& pY <= mBottomRight.GetY();
	}

	// 다른 사각형이 사각형에 포함되는지 확인
	bool contains(Rect other) {
		int x1 = mTopLeft.GetX();
		int x2 = mBottomRight.GetX();
		int y1 = mTopLeft.GetY();
		int y2 = mBottomRight.GetY();

		int otherX1 = other.mTopLeft.GetX();
		int otherX2 = other.mBottomRight.GetX();
		int otherY1 = other.mTopLeft.GetY();
		int otherY2 = other.mBottomRight.GetY();

		//다른 사각형의 좌상단 좌표값이 this사각형보다 크거나 같고
		//우하단 좌표값이 this사각형보다 작거나 같을때 포함
		return x1 <= otherX1
			&& x2 >= otherX2
			&& y1 <= otherY1
			&& y2 >= otherY2;
	}
};

