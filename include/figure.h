#ifndef FIGURE_H
#define FIGURE_H

#include "point.h"
#include <memory>
#include <iostream>

template<Scalar T>
class Figure {
public:
    virtual ~Figure() = default;







































































    virtual double area() const = 0;
    virtual Point<T> geometricCenter() const = 0;
    virtual void printVertices() const = 0;
    virtual operator double() const { return area(); }
    
    virtual bool operator==(const Figure& other) const {
        return area() == other.area();
    }
};

#endif
