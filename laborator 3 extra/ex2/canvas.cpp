#include "canvas.h"

Canvas::Canvas(int lines, int columns) {
    this->lines = lines;
    this->columns = columns;

    data = new char*[lines];
    for (int i = 0; i < lines; i++) {
        data[i] = new char[columns];
    }

    clear();
}

Canvas::~Canvas() {
    for (int i = 0; i < lines; i++) {
        delete[] data[i];
    }
    delete[] data;
}

void Canvas::set_pixel(int x, int y, char value) {
    if (x < 0 || x >= lines || y < 0 || y >= columns)
        return;

    data[x][y] = value;
}

void Canvas::set_pixels(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        int x = va_arg(args, int);
        int y = va_arg(args, int);
        int value = va_arg(args, int);

        set_pixel(x, y, (char)value);
    }

    va_end(args);
}

void Canvas::clear() {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            data[i][j] = ' ';
        }
    }
}

void Canvas::print() const {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << data[i][j];
        }
        std::cout << '\n';
    }
}