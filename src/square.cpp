template<Scalar T>
Square<T>::Square(Point<T> center, T side) 
    : center(std::make_unique<Point<T>>(center)), side(side) {}

template<Scalar T>
double Square<T>::area() const {
    return side * side;
}

template<Scalar T>
Point<T> Square<T>::geometricCenter() const {
    return *center;
}

template<Scalar T>
void Square<T>::printVertices() const {
    T halfSide = side / 2;
    Point<T> p1(center->getX() - halfSide, center->getY() - halfSide);
    Point<T> p2(center->getX() + halfSide, center->getY() - halfSide);
    Point<T> p3(center->getX() + halfSide, center->getY() + halfSide);
    Point<T> p4(center->getX() - halfSide, center->getY() + halfSide);
    
    std::cout << "Square vertices: " << p1 << ", " << p2 << ", " << p3 << ", " << p4 << std::endl;
}

template<Scalar T>
Square<T>::Square(const Square& other) 
    : center(std::make_unique<Point<T>>(*other.center)), side(other.side) {}

template<Scalar T>
Square<T>& Square<T>::operator=(const Square& other) {
    if (this != &other) {
        center = std::make_unique<Point<T>>(*other.center);
        side = other.side;
    }
    return *this;
}
