#include "MyFramedRectangle.h"
MyFramedRectangle::MyFramedRectangle(MyCanvas &c, unsigned int x, unsigned int y, unsigned int xx, unsigned int yy) : MyRectangle{c, x, y, xx, yy} {}
void MyFramedRectangle::draw()
{
    MyRectangle::draw();
    for (unsigned int i = y1; i <= y2; i++)
    {
        for (unsigned int i2 = x1; i2 <= x2; i2++)
        {
            if ((i == y1 || i == y2) || (i2 == x1 || i2 == x2))
                canvas_ptr->set(i2, i, '+');
        }
    }
}