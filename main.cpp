#include <iostream>
#include <memory>
#include "point.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"
#include "array.h"
#include "factory.h"

int main() {
    Array<std::shared_ptr<Figure<double>>> figures;
    
    int choice;
    do {
        std::cout << "\nMenu:\n";std::cout << "1. Add Triangle\n";std::cout << "2. Add Square\n";std::cout << "3. Add Rectangle\n";std::cout << "4. Print all figures\n";std::cout << "5. Calculate total area\n";
        std::cout << "6. Delete figure by index\n";std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                figures.push_back(createTriangle<double>());
                break;
            case 2:
                figures.push_back(createSquare<double>());
                break;
            case 3:
                figures.push_back(createRectangle<double>());
                break;
            case 4:
                figures.printAllFigures();
                break;
            case 5:
                std::cout << "Total area: " << figures.totalArea() << std::endl;
                break;
            case 6: {
                size_t index;
                std::cout << "Enter index to delete: ";
                std::cin >> index;
                if (index < figures.getSize()) {
                    figures.erase(index);
                    std::cout << "Figure deleted successfully.\n";
                } else {
                    std::cout << "Invalid index.\n";
                }
                break;
            }
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    
    // Пример работы с Array для разных типов
    std::cout << "\n=== Testing Array with different types ===\n";
    
    Array<std::shared_ptr<Figure<int>>> intFigures;
    intFigures.push_back(std::make_shared<Triangle<int>>(Point<int>(0, 0), Point<int>(1, 0), Point<int>(0, 1)));
    std::cout << "Array<Figure<int>*> test completed.\n";
    
    Array<Square<double>> squares;
    squares.push_back(Square<double>(Point<double>(0, 0), 5.0));
    std::cout << "Array<Square<double>> test completed.\n";
    
    return 0;
}
