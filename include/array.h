#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include "figure.h"

template<typename T>
class Array {
private:
    std::shared_ptr<T[]> data;
    size_t capacity;
    size_t size;
    
    void resize(size_t newCapacity);
    
public:
    Array();
    Array(size_t initialCapacity);
    
    void push_back(const T& value);
    void push_back(T&& value);
    void erase(size_t index);
    
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    
    size_t getSize() const;
    size_t getCapacity() const;
    
    double totalArea() const;
    void printAllFigures() const;
};

#include "array.cpp"

#endif
