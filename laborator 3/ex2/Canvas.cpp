#include "Canvas.h"
#include <iostream>
#include <cmath>

Canvas::Canvas(int width, int height)
{
    this->width = width;
    this->height = height;

    mat = new char*[height];
    for (int i = 0; i < height; i++)
    {
        mat[i] = new char[width];
        for (int j = 0; j < width; j++)
            mat[i][j] = ' ';
    }
}

Canvas::~Canvas()
{
    for (int i = 0; i < height; i++)
        delete[] mat[i];
    delete[] mat;
}

void Canvas::SetPoint(int x, int y, char ch)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
        mat[y][x] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    for (int x = left; x <= right; x++)
    {
        SetPoint(x, top, ch);
        SetPoint(x, bottom, ch);
    }

    for (int y = top; y <= bottom; y++)
    {
        SetPoint(left, y, ch);
        SetPoint(right, y, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int y = top; y <= bottom; y++)
        for (int x = left; x <= right; x++)
            SetPoint(x, y, ch);
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int dx = j - x;
            int dy = i - y;
            int dist2 = dx * dx + dy * dy;
            int r2 = ray * ray;

            if (dist2 >= r2 - ray && dist2 <= r2 + ray)
                SetPoint(j, i, ch);
        }
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int dx = j - x;
            int dy = i - y;

            if (dx * dx + dy * dy <= ray * ray)
                SetPoint(j, i, ch);
        }
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while (true)
    {
        SetPoint(x1, y1, ch);

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void Canvas::Print()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            std::cout << mat[i][j];
        std::cout << '\n';
    }
}

void Canvas::Clear()
{
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            mat[i][j] = ' ';
}