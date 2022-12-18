#pragma once
#include "MyRectangle.h"
class MyFramedRectangle : public MyRectangle
{
public:
    MyFramedRectangle(MyCanvas &c, unsigned int x, unsigned int y, unsigned int xx, unsigned int yy);
    void draw();
};