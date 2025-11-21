#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

































template<Scalar T>
class Triangle : public Figure<T> {
private:
    std::unique_ptr<Point<T>> p1, p2, p3;
public:
    Triangle(Point<T> a, Point<T> b, Point<T> c) 
        : p1(std::make_unique<Point<T>>(a))
        , p2(std::make_unique<Point<T>>(b))
        , p3(std::make_unique<Point<T>>(c)) {}
    
    double area() const override {
        T x1 = p1->getX(), y1 = p1->getY();
        T x2 = p2->getX(), y2 = p2->getY();
        T x3 = p3->getX(), y3 = p3->getY();
        
        return std::abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0);
    }
    
    Point<T> geometricCenter() const override {
        return (*p1 + *p2 + *p3) / 3;
    }
    
    void printVertices() const override {
        std::cout << "Triangle vertices: " << *p1 << ", " << *p2 << ", " << *p3 << std::endl;
    }
































































    Triangle(const Triangle& other) 
        : p1(std::make_unique<Point<T>>(*other.p1))
        , p2(std::make_unique<Point<T>>(*other.p2))
        , p3(std::make_unique<Point<T>>(*other.p3)) {}
    
    Triangle& operator=(const Triangle& other) {
        if (this != &other) {
            p1 = std::make_unique<Point<T>>(*other.p1);
            p2 = std::make_unique<Point<T>>(*other.p2);
            p3 = std::make_unique<Point<T>>(*other.p3);
        }
        return *this;
    }
};


















#endif
