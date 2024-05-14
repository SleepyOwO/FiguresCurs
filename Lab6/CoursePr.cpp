#include <iostream>
#include "FiguresList.h"
#include "Triangle.h"
#include "Trapeze.h"
#include "Complex.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleTitle((LPCWSTR)L"23VP1_25");
    //::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x2000);
    COORD p = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);

    figuresList li;
    Figure* Triangle = new triangle(500, 30, 60, 80, RGB(128, 0, 128), RGB(0, 0, 0));
    Figure* Trapeze = new trapeze(500, 140, 50, 100, 40, RGB(80, 200, 120), RGB(0, 0, 0));
    Figure* Complex = new complex(new triangle(500, 230, 70, 100, RGB(210, 210, 210), RGB(0, 0, 0)), new trapeze(500, 265, 50, 100, 35, RGB(210, 210, 0), RGB(0, 0, 0)));
    
    try {
        li.add_f({ Triangle, Trapeze, Complex });
        li.view();
    }
    catch (Figure::border) {
        cout << "\nНарушение границы окна";
    }

    Sleep(5000);

    //Sleep(50000);
    p = {1, 20};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
