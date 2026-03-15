#include "Sort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
#include <sstream>

bool Sort::Compare(int a, int b, bool ascendent)
{
    if (ascendent)
        return a > b;
    return a < b;
}

// constructor: random values in [min, max]
Sort::Sort(int count, int min, int max)
{
    std::srand((unsigned)std::time(nullptr));

    for (int i = 0; i < count; i++)
    {
        int value = min + std::rand() % (max - min + 1);
        elements.push_back(value);
    }
}

// constructor: initialization list
Sort::Sort(std::initializer_list<int> list)
{
    for (int x : list)
        elements.push_back(x);
}

// constructor: from existing vector and number of elements
Sort::Sort(const std::vector<int>& vec, int count)
{
    for (int i = 0; i < count && i < (int)vec.size(); i++)
        elements.push_back(vec[i]);
}

// constructor: variadic parameters
Sort::Sort(int count, ...)
{
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++)
    {
        int value = va_arg(args, int);
        elements.push_back(value);
    }

    va_end(args);
}

// constructor: from string "10,40,100,5,70"
Sort::Sort(const char* values)
{
    std::stringstream ss(values);
    std::string number;

    while (std::getline(ss, number, ','))
    {
        elements.push_back(std::stoi(number));
    }
}

// insertion sort
void Sort::InsertSort(bool ascendent)
{
    int n = (int)elements.size();

    for (int i = 1; i < n; i++)
    {
        int key = elements[i];
        int j = i - 1;

        while (j >= 0 && Compare(elements[j], key, ascendent))
        {
            elements[j + 1] = elements[j];
            j--;
        }

        elements[j + 1] = key;
    }
}

// quick sort helper
void Sort::QuickSortHelper(int left, int right, bool ascendent)
{
    int i = left;
    int j = right;
    int pivot = elements[(left + right) / 2];

    while (i <= j)
    {
        if (ascendent)
        {
            while (elements[i] < pivot) i++;
            while (elements[j] > pivot) j--;
        }
        else
        {
            while (elements[i] > pivot) i++;
            while (elements[j] < pivot) j--;
        }

        if (i <= j)
        {
            std::swap(elements[i], elements[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        QuickSortHelper(left, j, ascendent);
    if (i < right)
        QuickSortHelper(i, right, ascendent);
}

void Sort::QuickSort(bool ascendent)
{
    if (!elements.empty())
        QuickSortHelper(0, (int)elements.size() - 1, ascendent);
}

// bubble sort
void Sort::BubbleSort(bool ascendent)
{
    int n = (int)elements.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (Compare(elements[j], elements[j + 1], ascendent))
            {
                std::swap(elements[j], elements[j + 1]);
            }
        }
    }
}

void Sort::Print()
{
    for (int x : elements)
        std::cout << x << ' ';
    std::cout << '\n';
}

int Sort::GetElementsCount()
{
    return (int)elements.size();
}

int Sort::GetElementFromIndex(int index)
{
    if (index < 0 || index >= (int)elements.size())
        return -1;

    return elements[index];
}