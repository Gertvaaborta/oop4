#ifndef ARRAY_H
#define ARRAY_H

#include <memory>
#include <iostream>
#include "figure.h"

template<typename T>
class Array {
private:
    std::shared_ptr<T[]> data;
    size_t capacity;
    size_t size;
    
    void resize(size_t newCapacity) {
        std::shared_ptr<T[]> newData(new T[newCapacity]);
        
        for (size_t i = 0; i < size; ++i) {
            newData[i] = std::move(data[i]);
        }
        
        data = std::move(newData);
        capacity = newCapacity;
    }
    
public:
    Array() : data(nullptr), capacity(0), size(0) {}
    
    Array(size_t initialCapacity) : capacity(initialCapacity), size(0) {
        data = std::shared_ptr<T[]>(new T[capacity]);
    }
    
    void push_back(const T& value) {
        if (size >= capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = value;
    }
    
    void push_back(T&& value) {
        if (size >= capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = std::move(value);
    }
    
    void erase(size_t index) {
        if (index >= size) return;
        
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = std::move(data[i + 1]);
        }
        --size;
    }
    
    T& operator[](size_t index) {
        return data[index];
    }
    
    const T& operator[](size_t index) const {
        return data[index];
    }
    
    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }
    
    double totalArea() const {
        double total = 0;
        for (size_t i = 0; i < size; ++i) {
            total += static_cast<double>(*data[i]);
        }
        return total;
    }
    
    void printAllFigures() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << "Figure " << i + 1 << ":" << std::endl;
            data[i]->printVertices();
            std::cout << "Geometric center: " << data[i]->geometricCenter() << std::endl;
            std::cout << "Area: " << data[i]->area() << std::endl;
            std::cout << std::endl;
        }
    }
};

#endif
