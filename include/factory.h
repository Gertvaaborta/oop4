#ifndef FACTORY_H
#define FACTORY_H

#include "triangle.h"
#include "square.h"
#include "rectangle.h"
#include <memory>

template<Scalar T>
std::shared_ptr<Figure<T>> createTriangle() {
    T x1, y1, x2, y2, x3, y3;
    std::cout << "Enter triangle vertices (x1 y1 x2 y2 x3 y3): ";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    return std::make_shared<Triangle<T>>(Point<T>(x1, y1), Point<T>(x2, y2), Point<T>(x3, y3));
}

template<Scalar T>
std::shared_ptr<Figure<T>> createSquare() {
    T x, y, side;
    std::cout << "Enter square center and side (x y side): ";
    std::cin >> x >> y >> side;
    return std::make_shared<Square<T>>(Point<T>(x, y), side);
}

template<Scalar T>
std::shared_ptr<Figure<T>> createRectangle() {
    T x, y, width, height;
    std::cout << "Enter rectangle center, width and height (x y width height): ";
    std::cin >> x >> y >> width >> height;
    return std::make_shared<Rectangle<T>>(Point<T>(x, y), width, height);
}

#endif
