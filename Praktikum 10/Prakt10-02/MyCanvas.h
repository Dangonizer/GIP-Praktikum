#pragma once
#include <string>
class MyCanvas
{
protected:
    unsigned int size_x, size_y;
    char *canvas_array_ptr;

public:
    MyCanvas(unsigned int x, unsigned int y);

    ~MyCanvas();

    MyCanvas(const MyCanvas &source);

    MyCanvas &operator=(const MyCanvas &source);

    unsigned int get_size_x();
    unsigned int get_size_y();
    char *get_canvas_array_ptr();

    void set_size_x(unsigned int x);
    void set_size_y(unsigned int y);
    void set_canvas_array_ptr(char *p);

    void init();
    void set(unsigned int x, unsigned int y, char c);
    char get(unsigned int x, unsigned int y) const;
    std::string to_string() const;
    void print() const;
    void draw_rectangle(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
};
