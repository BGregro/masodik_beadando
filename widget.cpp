#include "widget.hpp"
#include "app.hpp"

Widget::Widget(int _x, int _y, int _sx, int _sy, App *_parent):
    x(_x), y(_y), sx(_sx), sy(_sy), parent(_parent)
{
    parent->addWidget(this);
}

bool Widget::is_selected(int mx, int my)
{
    return mx > x && mx < x+sx && my > y && my < y+sy;
}
