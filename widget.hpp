#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "graphics.hpp"

class Widget
{
protected:
    int x, y, sx, sy;
public:
    Widget(int x, int y, int sx, int sy);

    virtual bool is_selected(int mx, int my);
    virtual void draw() const = 0;
    virtual void handle(genv::event ev) = 0;
};

#endif // WIDGET_HPP
