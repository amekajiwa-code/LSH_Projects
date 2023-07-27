#include "GeometryUtils.h"

Point3D::Point3D(double x, double y, double z) : mX(x), mY(y), mZ(z) {}

Point3D::Point3D(const Point3D& other) : mX(other.mX), mY(other.mY), mZ(other.mZ) {}

bool Point3D::operator==(const Point3D& other) const {
    return (mX == other.mX) && (mY == other.mY) && (mZ == other.mZ);
}

bool Point3D::operator!=(const Point3D& other) const {
    return !(*this == other);
}

Point3D Point3D::operator+(const Point3D& other) const {
    return Point3D(mX + other.mX, mY + other.mY, mZ + other.mZ);
}

Point3D Point3D::operator-(const Point3D& other) const {
    return Point3D(mX - other.mX, mY - other.mY, mZ - other.mZ);
}

Point3D Point3D::operator*(double scalar) const {
    return Point3D(mX * scalar, mY * scalar, mZ * scalar);
}

Point3D Point3D::operator/(double scalar) const {
    if (scalar != 0.0) {
        return Point3D(mX / scalar, mY / scalar, mZ / scalar);
    }

    return *this;
}

Point3D& Point3D::operator=(const Point3D& other) {
    if (this != &other) {
        mX = other.mX;
        mY = other.mY;
        mZ = other.mZ;
    }
    return *this;
}

Box::Box(const Point3D& frontTopLeft,
    const Point3D& backBottomRight,
    double width, double height, double depth)
    : mFrontTopLeft(frontTopLeft), mWidth(width), mHeight(height), mDepth(depth) {
    mFrontTopRight = Point3D(frontTopLeft.getX() + width, frontTopLeft.getY(), frontTopLeft.getZ());
    mFrontBottomLeft = Point3D(frontTopLeft.getX(), frontTopLeft.getY() + height, frontTopLeft.getZ());
    mFrontBottomRight = Point3D(frontTopLeft.getX() + width, frontTopLeft.getY() + height, frontTopLeft.getZ());
    mBackTopLeft = Point3D(frontTopLeft.getX(), frontTopLeft.getY(), frontTopLeft.getZ() + depth);
    mBackTopRight = Point3D(frontTopLeft.getX() + width, frontTopLeft.getY(), frontTopLeft.getZ() + depth);
    mBackBottomLeft = Point3D(frontTopLeft.getX(), frontTopLeft.getY() + height, frontTopLeft.getZ() + depth);
    mBackBottomRight = Point3D(mBackTopLeft.getX() + width, mBackTopLeft.getY() + height, mBackTopLeft.getZ() + depth);
}