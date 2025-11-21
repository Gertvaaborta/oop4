template<Scalar T>
Point<T>::Point(T x, T y) : x(x), y(y) {}

template<Scalar T>
T Point<T>::getX() const { return x; }

template<Scalar T>
T Point<T>::getY() const { return y; }

template<Scalar T>
void Point<T>::setX(T x) { this->x = x; }

template<Scalar T>
void Point<T>::setY(T y) { this->y = y; }

template<Scalar T>
double Point<T>::distanceTo(const Point& other) const {
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}

template<Scalar T>
Point<T> Point<T>::operator+(const Point& other) const {
    return Point(x + other.x, y + other.y);
}

template<Scalar T>
Point<T> Point<T>::operator/(T divisor) const {
    return Point(x / divisor, y / divisor);
}

template<Scalar T>
std::ostream& operator<<(std::ostream& os, const Point<T>& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}
