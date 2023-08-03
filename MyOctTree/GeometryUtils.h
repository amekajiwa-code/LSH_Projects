#ifndef GEOMETRY_UTILS_H
#define GEOMETRY_UTILS_H

#include <cmath>

class Vector3 {
public:
    union {
        struct {
            double mX, mY, mZ;
        };
        double v[3];
    };
public:
    Vector3() : mX(0), mY(0), mZ(0) {}
    Vector3(double x, double y, double z);
    Vector3(const Vector3& other);

    bool operator==(const Vector3& other) const;
    bool operator!=(const Vector3& other) const;
    Vector3 operator+(const Vector3& other) const;
    Vector3 operator-(const Vector3& other) const;
    Vector3 operator*(double scalar) const;
    Vector3 operator/(double scalar) const;
    Vector3& operator=(const Vector3& other);

    double getX() const { return mX; }
    double getY() const { return mY; }
    double getZ() const { return mZ; }

    void Normalize() {
        double length = std::sqrt(mX * mX + mY * mY + mZ * mZ);
        if (length != 0.0f) {
            mX /= length;
            mY /= length;
            mZ /= length;
        }
    }
};

class Box {
public:
    Vector3 mFrontTopLeft;
    Vector3 mFrontTopRight;
    Vector3 mFrontBottomLeft;
    Vector3 mFrontBottomRight;
    Vector3 mBackTopLeft;
    Vector3 mBackTopRight;
    Vector3 mBackBottomLeft;
    Vector3 mBackBottomRight;
    double mWidth, mHeight, mDepth;

    Box() {
        mWidth = 0, mHeight = 0, mDepth = 0;
    };
    Box(const Vector3& frontTopLeft,
        const Vector3& backBottomRight,
        double width, double height, double depth);

    void Set(const Vector3& frontTopLeft,
        const Vector3& backBottomRight,
        double width, double height, double depth) {
        mFrontTopLeft = frontTopLeft;
        mFrontTopRight = Vector3(backBottomRight.getX(), frontTopLeft.getY(), frontTopLeft.getZ());
        mFrontBottomLeft = Vector3(frontTopLeft.getX(), backBottomRight.getY(), frontTopLeft.getZ());
        mFrontBottomRight = Vector3(backBottomRight.getX(), backBottomRight.getY(), frontTopLeft.getZ());
        mBackTopLeft = Vector3(frontTopLeft.getX(), frontTopLeft.getY(), backBottomRight.getZ());
        mBackTopRight = Vector3(backBottomRight.getX(), frontTopLeft.getY(), backBottomRight.getZ());
        mBackBottomLeft = Vector3(frontTopLeft.getX(), backBottomRight.getY(), backBottomRight.getZ());
        mBackBottomRight = backBottomRight;
        mWidth = width;
        mHeight = height;
        mDepth = depth;
    }
};

#endif