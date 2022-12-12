#include <iostream>
#include "MyCanvas.h"

MyCanvas::MyCanvas(unsigned int x, unsigned int y) : size_x{x}, size_y{y}, canvas_array_ptr{new char[size_x * size_y]} { init(); }

MyCanvas::~MyCanvas() { delete canvas_array_ptr; }

MyCanvas::MyCanvas(const MyCanvas &source) : size_x{source.size_x}, size_y{source.size_y}
{
    canvas_array_ptr = new char[source.size_x * source.size_y];
    for (unsigned int i = 0; i < size_x * size_y; i++)
    {
        canvas_array_ptr[i] = source.canvas_array_ptr[i];
    }
}

MyCanvas &MyCanvas::operator=(const MyCanvas &source)
{
    delete canvas_array_ptr;
    size_x = source.size_x;
    size_y = source.size_y;
    canvas_array_ptr = new char[size_x * size_y];
    for (unsigned int i = 0; i < size_x * size_y; i++)
    {
        canvas_array_ptr[i] = source.canvas_array_ptr[i];
    }
    return *this;
}

unsigned int MyCanvas::get_size_x() { return size_x; }
unsigned int MyCanvas::get_size_y() { return size_y; }
char *MyCanvas::get_canvas_array_ptr() { return canvas_array_ptr; }

void MyCanvas::set_size_x(unsigned int x) { size_x = x; }
void MyCanvas::set_size_y(unsigned int y) { size_y = y; }
void MyCanvas::set_canvas_array_ptr(char *p) { canvas_array_ptr = p; }

void MyCanvas::init()
{
    for (unsigned int i = 0; i < size_x * size_y; i++)
    {
        canvas_array_ptr[i] = '.';
    }
}

void MyCanvas::set(unsigned int x, unsigned int y, char c)
{
    canvas_array_ptr[size_x * y + x] = c;
}

char MyCanvas::get(unsigned int x, unsigned int y) const
{
    return canvas_array_ptr[size_x * y + x];
}

std::string MyCanvas::to_string() const
{
    std::string output = "";
    for (unsigned int i = 0; i < size_x * size_y; i++)
    {
        output += canvas_array_ptr[i];
        if ((i + 1) % size_x == 0)
            output += "\n";
    }
    return output;
}

void MyCanvas::print() const
{
    std::cout << to_string() << std::endl;
}
