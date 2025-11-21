template<Scalar T>
Rectangle<T>::Rectangle(Point<T> center, T width, T height) 
    : center(std::make_unique<Point<T>>(center)), width(width), height(height) {}

template<Scalar T>
double Rectangle<T>::area() const {
    return width * height;
}

template<Scalar T>
Point<T> Rectangle<T>::geometricCenter() const {
    return *center;
}

template<Scalar T>
void Rectangle<T>::printVertices() const {
    T halfWidth = width / 2;
    T halfHeight = height / 2;
    Point<T> p1(center->getX() - halfWidth, center->getY() - halfHeight);
    Point<T> p2(center->getX() + halfWidth, center->getY() - halfHeight);
    Point<T> p3(center->getX() + halfWidth, center->getY() + halfHeight);
    Point<T> p4(center->getX() - halfWidth, center->getY() + halfHeight);
    
    std::cout << "Rectangle vertices: " << p1 << ", " << p2 << ", " << p3 << ", " << p4 << std::endl;
}

template<Scalar T>
Rectangle<T>::Rectangle(const Rectangle& other) 
    : center(std::make_unique<Point<T>>(*other.center)), width(other.width), height(other.height) {}

template<Scalar T>
Rectangle<T>& Rectangle<T>::operator=(const Rectangle& other) {
    if (this != &other) {
        center = std::make_unique<Point<T>>(*other.center);
        width = other.width;
        height = other.height;
    }
    return *this;
}
