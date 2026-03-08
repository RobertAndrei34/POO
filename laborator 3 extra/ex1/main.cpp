#include <iostream>
#include "Math.h"

int main()
{
    std::cout << "Add(int, int): " << Math::Add(2, 3) << '\n';
    std::cout << "Add(int, int, int): " << Math::Add(2, 3, 4) << '\n';

    std::cout << "Add(double, double): " << Math::Add(2.5, 3.7) << '\n';
    std::cout << "Add(double, double, double): " << Math::Add(1.2, 2.3, 3.4) << '\n';

    std::cout << "Mul(int, int): " << Math::Mul(2, 3) << '\n';
    std::cout << "Mul(int, int, int): " << Math::Mul(2, 3, 4) << '\n';

    std::cout << "Mul(double, double): " << Math::Mul(2.5, 3.0) << '\n';
    std::cout << "Mul(double, double, double): " << Math::Mul(1.5, 2.0, 3.0) << '\n';

    std::cout << "Add(count, ...): " << Math::Add(5, 1, 2, 3, 4, 5) << '\n';

    char* text = Math::Add("Hello, ", "world!");
    if (text != nullptr)
    {
        std::cout << "Add(const char*, const char*): " << text << '\n';
        delete[] text;
    }

    char* testNull = Math::Add(nullptr, "abc");
    if (testNull == nullptr)
    {
        std::cout << "Add(nullptr, \"abc\"): nullptr\n";
    }

    return 0;
}