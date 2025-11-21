#include <iostream>
#include <memory>
#include "point.h"
#include "triangle.h"
#include "square.h"
#include "rectangle.h"
#include "array.h"
#include "factory.h"

using namespace std;

void showMenu() {
    cout << "\n=== Меню работы с фигурами ===" << endl;
    cout << "1. Добавить треугольник" << endl;
    cout << "2. Добавить квадрат" << endl;
    cout << "3. Добавить прямоугольник" << endl;
    cout << "4. Показать все фигуры" << endl;
    cout << "5. Посчитать общую площадь" << endl;
    cout << "6. Удалить фигуру" << endl;
    cout << "7. Демонстрация работы с разными типами" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите действие: ";
}

void addTriangle(Array<shared_ptr<Figure<double>>>& figures) {
    cout << "\n--- Добавление треугольника ---" << endl;
    try {
        auto triangle = createTriangle<double>();
        figures.push_back(triangle);
        cout << "Треугольник успешно добавлен!" << endl;
    } catch (const exception& e) {
        cout << "Ошибка при создании треугольника: " << e.what() << endl;
    }
}

void addSquare(Array<shared_ptr<Figure<double>>>& figures) {
    cout << "\n--- Добавление квадрата ---" << endl;
    try {
        auto square = createSquare<double>();
        figures.push_back(square);
        cout << "Квадрат успешно добавлен!" << endl;
    } catch (const exception& e) {
        cout << "Ошибка при создании квадрата: " << e.what() << endl;
    }
}

void addRectangle(Array<shared_ptr<Figure<double>>>& figures) {
    cout << "\n--- Добавление прямоугольника ---" << endl;
    try {
        auto rectangle = createRectangle<double>();
        figures.push_back(rectangle);
        cout << "Прямоугольник успешно добавлен!" << endl;
    } catch (const exception& e) {
        cout << "Ошибка при создании прямоугольника: " << e.what() << endl;
    }
}

void showAllFigures(Array<shared_ptr<Figure<double>>>& figures) {
    cout << "\n--- Список всех фигур ---" << endl;
    if (figures.getSize() == 0) {
        cout << "Фигур пока нет." << endl;
        return;
    }
    figures.printAllFigures();
}

void showTotalArea(Array<shared_ptr<Figure<double>>>& figures) {
    cout << "\n--- Общая площадь ---" << endl;
    if (figures.getSize() == 0) {
        cout << "Нет фигур для расчета площади." << endl;
        return;
    }
    double total = figures.totalArea();
    cout << "Общая площадь всех фигур: " << total << endl;
}

void deleteFigure(Array<shared_ptr<Figure<double>>>& figures) {
    cout << "\n--- Удаление фигуры ---" << endl;
    if (figures.getSize() == 0) {
        cout << "Нет фигур для удаления." << endl;
        return;
    }
    
    cout << "Всего фигур: " << figures.getSize() << endl;
    cout << "Введите номер фигуры для удаления (от 0 до " << figures.getSize() - 1 << "): ";
    
    size_t index;
    cin >> index;
    
    if (index < figures.getSize()) {
        figures.erase(index);
        cout << "Фигура успешно удалена!" << endl;
    } else {
        cout << "Неверный номер фигуры!" << endl;
    }
}

void demonstrateDifferentTypes() {
    cout << "\n--- Демонстрация работы с разными типами ---" << endl;
    
    // Работа с целыми числами
    cout << "1. Работа с типом int:" << endl;
    Array<shared_ptr<Figure<int>>> intFigures;
    Point<int> p1(0, 0), p2(4, 0), p3(0, 3);
    auto intTriangle = make_shared<Triangle<int>>(p1, p2, p3);
    intFigures.push_back(intTriangle);
    cout << "   Площадь треугольника с целыми координатами: " << intTriangle->area() << endl;
    
    // Работа с float
    cout << "2. Работа с типом float:" << endl;
    Array<shared_ptr<Figure<float>>> floatFigures;
    Point<float> center(2.5f, 2.5f);
    auto floatSquare = make_shared<Square<float>>(center, 3.0f);
    floatFigures.push_back(floatSquare);
    cout << "   Площадь квадрата с float: " << floatSquare->area() << endl;
    
    // Прямое хранение объектов (не указателей)
    cout << "3. Прямое хранение объектов Square:" << endl;
    Array<Square<double>> directSquares;
    Point<double> directCenter(1.0, 1.0);
    Square<double> squareObj(directCenter, 2.0);
    directSquares.push_back(squareObj);
    cout << "   Квадрат добавлен в массив прямых объектов" << endl;
    
    cout << "Демонстрация завершена успешно!" << endl;
}

int main() {
    cout << "Программа для работы с геометрическими фигурами" << endl;
    cout << "=============================================" << endl;
    
    Array<shared_ptr<Figure<double>>> figures;
    
    int choice;
    do {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                addTriangle(figures);
                break;
            case 2:
                addSquare(figures);
                break;
            case 3:
                addRectangle(figures);
                break;
            case 4:
                showAllFigures(figures);
                break;
            case 5:
                showTotalArea(figures);
                break;
            case 6:
                deleteFigure(figures);
                break;
            case 7:
                demonstrateDifferentTypes();
                break;
            case 0:
                cout << "\nВыход из программы. До свидания!" << endl;
                break;
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
                break;
        }
        
        // Небольшая пауза для удобства чтения
        if (choice != 0) {
            cout << "\nНажмите Enter для продолжения...";
            cin.ignore();
            cin.get();
        }
        
    } while (choice != 0);
    
    return 0;
}
