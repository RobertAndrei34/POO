#include <iostream>
#include "Canvas.h"

int main()
{
    Canvas c(40, 20);

    c.SetPoint(1, 1, 'A');
    c.DrawRect(3, 2, 12, 6, '#');
    c.FillRect(14, 2, 22, 6, '.');
    c.DrawCircle(10, 14, 4, '*');
    c.FillCircle(25, 14, 3, '@');
    c.DrawLine(0, 0, 39, 19, '/');

    std::cout << "Canvas after drawing:\n";
    c.Print();

    c.Clear();
    std::cout << "\nCanvas after clear:\n";
    c.Print();

    return 0;
}