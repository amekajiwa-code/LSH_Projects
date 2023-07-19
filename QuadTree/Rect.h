#pragma once
#include "Point.h"
class Rect
{
private:
	Point mTopLeft;
	Point mbottomRight;
public:
	Rect(Point topLeft, int width, int height) {
		mTopLeft = topLeft;
		Point tempPoint(topLeft.GetX() + width, topLeft.GetY() + height);
		mbottomRight(tempPoint);
	}
};

