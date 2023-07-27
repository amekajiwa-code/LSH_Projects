#ifndef GEOMETRY_UTILS_H
#define GEOMETRY_UTILS_H

class Point3D {
private:
    union {
        struct {
            double mX, mY, mZ;
        };
        double v[3];
    };
public:
    Point3D() : mX(0), mY(0), mZ(0) {}
    Point3D(double x, double y, double z);
    Point3D(const Point3D& other);

    bool operator==(const Point3D& other) const;
    bool operator!=(const Point3D& other) const;
    Point3D operator+(const Point3D& other) const;
    Point3D operator-(const Point3D& other) const;
    Point3D operator*(double scalar) const;
    Point3D operator/(double scalar) const;
    Point3D& operator=(const Point3D& other);

    double getX() const { return mX; }
    double getY() const { return mY; }
    double getZ() const { return mZ; }
};

class Box {
private:
    Point3D mFrontTopLeft;
    Point3D mFrontTopRight;
    Point3D mFrontBottomLeft;
    Point3D mFrontBottomRight;
    Point3D mBackTopLeft;
    Point3D mBackTopRight;
    Point3D mBackBottomLeft;
    Point3D mBackBottomRight;
    double mWidth, mHeight, mDepth;
public:
    Box(const Point3D& frontTopLeft,
        const Point3D& backBottomRight,
        double width, double height, double depth);
};

#endif