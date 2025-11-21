#include <iostream>
#include <memory>
#include <figures/point.h>
#include <figures/figure.h>
#include <figures/triangle.h>
#include <figures/square.h>
#include <figures/rectangle.h>
#include <figures/array.h>
#include <figures/factory.h>

int main() {
    Array<std::shared_ptr<Figure<double>>> figures;
    
    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Triangle\n";
        std::cout << "2. Add Square\n";
        std::cout << "3. Add Rectangle\n";
        std::cout << "4. Print all figures\n";
        std::cout << "5. Calculate total area\n";
        std::cout << "6. Delete figure by index\n";
        std::cout << "0. Exit\n";
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
    
    return 0;
}
