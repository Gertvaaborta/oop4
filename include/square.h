#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

template<Scalar T>
class Square : public Figure<T> {
private:
    std::unique_ptr<Point<T>> center;
    T side;
public:
    Square(Point<T> center, T side);
    double area() const override;
    Point<T> geometricCenter() const override;
    void printVertices() const override;
    
    Square(const Square& other);
    Square& operator=(const Square& other);
};

#include "square.cpp"

#endif
