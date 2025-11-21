#include <iostream>
#include <point.h>
#include <triangle.h>
#include <square.h>
#include <rectangle.h>
#include <array.h>

int main() {
    Array<std::shared_ptr<Figure<double>>> figures;
    
    // Добавляем тестовые фигуры
    Point<double> center(0, 0);
    auto triangle = std::make_shared<Triangle<double>>(
        Point<double>(0, 0), Point<double>(3, 0), Point<double>(0, 4)
    );
    auto square = std::make_shared<Square<double>>(center, 2.0);
    auto rectangle = std::make_shared<Rectangle<double>>(center, 3.0, 2.0);
    
    figures.push_back(triangle);
    figures.push_back(square);
    figures.push_back(rectangle);
    
    // Выводим информацию
    std::cout << "Total figures: " << figures.getSize() << std::endl;
    std::cout << "Total area: " << figures.totalArea() << std::endl;
    std::cout << "\nAll figures:\n";
    figures.printAllFigures();
    
    return 0;
}
