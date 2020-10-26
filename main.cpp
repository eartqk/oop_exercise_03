/*
Артамонов Олег М80-208Б-19
Разработать классы треугольника, квадрата и восьмиугольника,
которые наследуются от базового Figure.h.
Необходимо вводить/выводить фигуры с помощью std::cin/std::cout
Сохранять фигуры в динамический массив std::vector<Figure*>.
Вызывать для всего массива общие функции(вычисление геометрического центра,
вычисление площади фигуры, вывод в стандартнй поток координаты вершин фигуры).
Возможность удаления фигуры из массива по индексу.
*/

#include "Figure.h"
#include "Octagon.h"
#include "Square.h"
#include "Triangle.h"
#include <iostream>
#include <vector>

using namespace std;

double totalArea(vector<Figure*> figures)
{
    double resultSquare = 0;
    for (auto& figure : figures) {
        resultSquare = resultSquare + figure->Area();
    }
    return resultSquare;
}
void Help()
{
    cout << "1. Add triangle.\n2. Add square.\n3. Add octagon.\n4. Delete a "
            "figure.\n5. Total area.\n6. Help.\n7. Print.\n8. Exit.\n";
}

int main()
{
    vector<Figure*> figures;
    double x, y, side;
    int command = 0;
    Help();
    while (command != 8) {
        cout << "Enter the command: ";
        cin >> command;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input" << std::endl;
            cin >> command;
        }
        switch (command) {
        case 1: {
            cout << "Enter the left bottom coordinate (x and y) and side: ";
            cin >> x >> y >> side;
            if (side < 0) {
                cout << "Incorrect input!\n";
                break;
            }
            Figure* triangle = new Triangle(x, y, side);
            figures.push_back(triangle);
            break;
        }
        case 2: {
            cout << "Enter the left bottom coordinate (x and y) and side: ";
            cin >> x >> y >> side;
            if (side < 0) {
                cout << "Incorrect input!\n";
                break;
            }
            Figure* square = new Square(x, y, side);
            figures.push_back(square);
            break;
        }
        case 3: {
            cout << "Enter the most bottom and left coordinate (x and y) and "
                    "side: ";
            cin >> x >> y >> side;
            if (side < 0) {
                cout << "Incorrect input!\n";
                break;
            }
            Figure* octagon = new Octagon(x, y, side);
            figures.push_back(octagon);
            break;
        }
        case 4: {
            int id;
            cout << "Enter id of the figure: ";
            cin >> id;
            if (id < 0 || id > figures.size()) {
                cout << "Incorrect input!\n";
                break;
            }
            figures.erase(figures.begin() + id);
            break;
        }
        case 5: {
            cout << "Square of all shapes: " << totalArea(figures) << endl;
            break;
        }
        case 6:
            Help();
            break;
        case 7: {
            for (auto& figure : figures) {
                cout << endl;
                figure->Print();
                cout << "Center: " << figure->Center() << endl;
                cout << "Area: " << figure->Area() << endl;
            }
            break;
        }
        case 8:
            break;
        default:
            cout << "Incorrect command!\n";
            break;
        }
    }
    return 0;
}
