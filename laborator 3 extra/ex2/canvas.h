#pragma once
#include <cstdarg>
#include <iostream>

class Canvas {
    int lines, columns;
    char** data;

  public:
    Canvas(int lines, int columns);

    // destructor
    ~Canvas();

    void set_pixel(int x, int y, char value);

    void set_pixels(int count, ...);

    void clear();
    void print() const;
};