#ifndef GEOMETRY_UTILS_H
#define GEOMETRY_UTILS_H

class Vector3 {
private:
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
};

#endif