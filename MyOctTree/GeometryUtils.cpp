#include "GeometryUtils.h"

Vector3::Vector3(double x, double y, double z) : mX(x), mY(y), mZ(z) {}

Vector3::Vector3(const Vector3& other) : mX(other.mX), mY(other.mY), mZ(other.mZ) {}

bool Vector3::operator==(const Vector3& other) const {
    return (mX == other.mX) && (mY == other.mY) && (mZ == other.mZ);
}

bool Vector3::operator!=(const Vector3& other) const {
    return !(*this == other);
}

Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(mX + other.mX, mY + other.mY, mZ + other.mZ);
}

Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(mX - other.mX, mY - other.mY, mZ - other.mZ);
}

Vector3 Vector3::operator*(double scalar) const {
    return Vector3(mX * scalar, mY * scalar, mZ * scalar);
}

Vector3 Vector3::operator/(double scalar) const {
    if (scalar != 0.0) {
        return Vector3(mX / scalar, mY / scalar, mZ / scalar);
    }

    return *this;
}

Vector3& Vector3::operator=(const Vector3& other) {
    if (this != &other) {
        mX = other.mX;
        mY = other.mY;
        mZ = other.mZ;
    }
    return *this;
}

Box::Box(const Vector3& frontTopLeft,
    const Vector3& backBottomRight,
    double width, double height, double depth)
    : mFrontTopLeft(frontTopLeft), mWidth(width), mHeight(height), mDepth(depth) {
    mFrontTopRight = Vector3(frontTopLeft.getX() + width, frontTopLeft.getY(), frontTopLeft.getZ());
    mFrontBottomLeft = Vector3(frontTopLeft.getX(), frontTopLeft.getY() + height, frontTopLeft.getZ());
    mFrontBottomRight = Vector3(frontTopLeft.getX() + width, frontTopLeft.getY() + height, frontTopLeft.getZ());
    mBackTopLeft = Vector3(frontTopLeft.getX(), frontTopLeft.getY(), frontTopLeft.getZ() + depth);
    mBackTopRight = Vector3(frontTopLeft.getX() + width, frontTopLeft.getY(), frontTopLeft.getZ() + depth);
    mBackBottomLeft = Vector3(frontTopLeft.getX(), frontTopLeft.getY() + height, frontTopLeft.getZ() + depth);
    mBackBottomRight = Vector3(mBackTopLeft.getX() + width, mBackTopLeft.getY() + height, mBackTopLeft.getZ() + depth);
}