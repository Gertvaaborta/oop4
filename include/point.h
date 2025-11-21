#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>
#include <concepts>

template<typename T>
concept Scalar = std::is_scalar_v<T>;

template<Scalar T>
class Point {
private:
    T x, y;
public:
    Point(T x = 0, T y = 0);
    
    T getX() const;
    T getY() const;
    
    void setX(T x);
    void setY(T y);
    
    double distanceTo(const Point& other) const;
    
    Point operator+(const Point& other) const;
    Point operator/(T divisor) const;
    
    template<Scalar U>
    friend std::ostream& operator<<(std::ostream& os, const Point<U>& point);
};

#include "point.cpp"

#endif
