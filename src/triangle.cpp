template<Scalar T>
Triangle<T>::Triangle(Point<T> a, Point<T> b, Point<T> c) 
    : p1(std::make_unique<Point<T>>(a))
    , p2(std::make_unique<Point<T>>(b))
    , p3(std::make_unique<Point<T>>(c)) {}

template<Scalar T>
double Triangle<T>::area() const {
    T x1 = p1->getX(), y1 = p1->getY();
    T x2 = p2->getX(), y2 = p2->getY();
    T x3 = p3->getX(), y3 = p3->getY();
    
    return std::abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0);
}

template<Scalar T>
Point<T> Triangle<T>::geometricCenter() const {
    return (*p1 + *p2 + *p3) / 3;
}

template<Scalar T>
void Triangle<T>::printVertices() const {
    std::cout << "Triangle vertices: " << *p1 << ", " << *p2 << ", " << *p3 << std::endl;
}

template<Scalar T>
Triangle<T>::Triangle(const Triangle& other) 
    : p1(std::make_unique<Point<T>>(*other.p1))
    , p2(std::make_unique<Point<T>>(*other.p2))
    , p3(std::make_unique<Point<T>>(*other.p3)) {}

template<Scalar T>
Triangle<T>& Triangle<T>::operator=(const Triangle& other) {
    if (this != &other) {
        p1 = std::make_unique<Point<T>>(*other.p1);
        p2 = std::make_unique<Point<T>>(*other.p2);
        p3 = std::make_unique<Point<T>>(*other.p3);
    }
    return *this;
}
