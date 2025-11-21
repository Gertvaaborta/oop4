template<typename T>
void Array<T>::resize(size_t newCapacity) {
    std::shared_ptr<T[]> newData(new T[newCapacity]);
    
    for (size_t i = 0; i < size; ++i) {
        newData[i] = std::move(data[i]);
    }
    
    data = std::move(newData);
    capacity = newCapacity;
}

template<typename T>
Array<T>::Array() : data(nullptr), capacity(0), size(0) {}

template<typename T>
Array<T>::Array(size_t initialCapacity) : capacity(initialCapacity), size(0) {
    data = std::shared_ptr<T[]>(new T[capacity]);
}

template<typename T>
void Array<T>::push_back(const T& value) {
    if (size >= capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
}

template<typename T>
void Array<T>::push_back(T&& value) {
    if (size >= capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = std::move(value);
}

template<typename T>
void Array<T>::erase(size_t index) {
    if (index >= size) return;
    
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = std::move(data[i + 1]);
    }
    --size;
}

template<typename T>
T& Array<T>::operator[](size_t index) {
    return data[index];
}

template<typename T>
const T& Array<T>::operator[](size_t index) const {
    return data[index];
}

template<typename T>
size_t Array<T>::getSize() const { return size; }

template<typename T>
size_t Array<T>::getCapacity() const { return capacity; }

template<typename T>
double Array<T>::totalArea() const {
    double total = 0;
    for (size_t i = 0; i < size; ++i) {
        total += static_cast<double>(*data[i]);
    }
    return total;
}

template<typename T>
void Array<T>::printAllFigures() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << "Figure " << i + 1 << ":" << std::endl;
        data[i]->printVertices();
        std::cout << "Geometric center: " << data[i]->geometricCenter() << std::endl;
        std::cout << "Area: " << data[i]->area() << std::endl;
        std::cout << std::endl;
    }
}
