#pragma once
#include "MyCanvas.h"
class MyRectangle
{
protected:
    unsigned int x1, x2, y1, y2;
    MyCanvas *canvas_ptr;

public:
    MyRectangle(MyCanvas &c, unsigned int x, unsigned int y, unsigned int xx, unsigned int yy);

    MyRectangle operator*(int factor) const;

    unsigned int get_x1();
    unsigned int get_x2();
    unsigned int get_y1();
    unsigned int get_y2();
    MyCanvas *get_canvas_ptr();

    void set_x1(unsigned int value);
    void set_x2(unsigned int value);
    void set_y1(unsigned int value);
    void set_y2(unsigned int value);
    void set_canvas_ptr(MyCanvas *value);

    void draw();
};
