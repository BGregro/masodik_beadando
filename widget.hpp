#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "graphics.hpp"

class App;

class Widget
{
protected:
    int x, y, sx, sy;
    App *parent;
public:
    Widget(int x, int y, int sx, int sy, App *parent);

    virtual bool is_selected(int mx, int my);
    virtual void draw() const = 0;
    virtual void handle(genv::event ev) = 0;
};

#endif // WIDGET_HPP
