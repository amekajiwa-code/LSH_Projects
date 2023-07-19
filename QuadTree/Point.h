#pragma once
class Point
{
private:
	int mX;
	int mY;
public:
	Point() {
		mX = 0;
		mY = 0;
	}

	Point(const int x, const int y) {
		mX = x;
		mY = y;
	}
	//복사생성자
	Point(const Point& other) {
		mX = other.mX;
		mY = other.mY;
	}

	int GetX() const {
		return mX;
	}

	int GetY() const {
		return mY;
	}
};

