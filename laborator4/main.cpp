#include <iostream>
#include <vector>
#include "Sort.h"

int main()
{
    // 1. random values constructor
    Sort s1(10, 1, 100);
    std::cout << "Random list:\n";
    s1.Print();

    s1.InsertSort(true);
    std::cout << "After InsertSort ascending:\n";
    s1.Print();

    // 2. initialization list constructor
    Sort s2({10, 40, 100, 5, 70});
    std::cout << "\nInitialization list:\n";
    s2.Print();

    s2.QuickSort(false);
    std::cout << "After QuickSort descending:\n";
    s2.Print();

    // 3. vector constructor
    std::vector<int> v = {8, 3, 9, 1, 6, 2, 7};
    Sort s3(v, 5);
    std::cout << "\nFrom vector (first 5 elements):\n";
    s3.Print();

    s3.BubbleSort(true);
    std::cout << "After BubbleSort ascending:\n";
    s3.Print();

    // 4. variadic constructor
    Sort s4(6, 15, 4, 22, 8, 11, 3);
    std::cout << "\nVariadic constructor:\n";
    s4.Print();

    // 5. string constructor
    Sort s5("10,40,100,5,70");
    std::cout << "\nFrom string:\n";
    s5.Print();

    std::cout << "Elements count: " << s5.GetElementsCount() << '\n';
    std::cout << "Element at index 2: " << s5.GetElementFromIndex(2) << '\n';

    return 0;
}