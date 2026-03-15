#pragma once
#include <vector>
#include <string>
#include <initializer_list>

class Sort
{
private:
    std::vector<int> elements;

    bool Compare(int a, int b, bool ascendent);
    void QuickSortHelper(int left, int right, bool ascendent);

public:
    // constructors
    Sort(int count, int min, int max);
    Sort(std::initializer_list<int> list);
    Sort(const std::vector<int>& vec, int count);
    Sort(int count, ...);
    Sort(const char* values);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};