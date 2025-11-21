#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

template<Scalar T>
class Triangle : public Figure<T> {
private:
    std::unique_ptr<Point<T>> p1, p2, p3;
public:
    Triangle(Point<T> a, Point<T> b, Point<T> c);
    double area() const override;
    Point<T> geometricCenter() const override;
    void printVertices() const override;
    
    Triangle(const Triangle& other);
    Triangle& operator=(const Triangle& other);
};

#include "triangle.cpp"

#endif
