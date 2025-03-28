#ifndef WIDGET_HPP
#define WIDGET_HPP

class Widget
{
protected:
    int x, y, sx, sy;
public:
    Widget(int x, int y, int sx, int sy);

    virtual void draw();

};

#endif // WIDGET_HPP
