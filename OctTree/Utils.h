#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <math.h>

class Utils
{
	struct Point2 {
		float x = 0.0f;
		float y = 0.0f;
		
		float GetDistance() {
			float distance = sqrt(x * x + y * y);
		}
	};

	struct Float2 {
		union {
			struct {
				float mX;
				float mY;
			};
			float v[2];
		};
	};

	struct Float3 {
		union {
			struct {
				float mX;
				float mY;
				float mZ;
			};
			float v[3];
		};
	};

	struct Rect : Float2 {
		bool mEnable = true;
		float mWidth = 0.0f;
		float mHeight = 0.0f;
		Point2 mPoint[4];
		Point2 mCenter;
		Point2 mHalf;
		Point2 mMin;
		Point2 mMax;
		Point2 v;
		Point2 s;

		bool Intersect(Rect& p, Rect& ret) {
			return false;
		}

		void Set(Point2 point) {
			v = { point.x, point.y };
			s = { mWidth, mHeight };
			mX = mX;
			mY = mY;
		}

		void Set(float fw, float fh)
		{
			mWidth = fw;
			mHeight = fh;
			mHalf = { mWidth * 0.5f,mHeight * 0.5f };
			mPoint[0] = { mX, mY };
			mPoint[1] = { mX + mWidth, mY };
			mPoint[2] = { mX + mWidth, mY + mHeight };
			mPoint[3] = { mX, mY + mHeight };
			mCenter = (mPoint[0] + mPoint[2]) * 0.5f;
			mMin = mPoint[0];
			mMax = mPoint[2];
		}
	};
};

