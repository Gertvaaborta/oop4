#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

template<Scalar T>
class Rectangle : public Figure<T> {
private:
    std::unique_ptr<Point<T>> center;
    T width, height;
public:
    Rectangle(Point<T> center, T width, T height);
    double area() const override;
    Point<T> geometricCenter() const override;
    void printVertices() const override;
    
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
};

#include "rectangle.cpp"

#endif
