#ifndef NUMBERBOX_HPP
#define NUMBERBOX_HPP

#include "widget.hpp"

class NumberBox : public Widget
{
public:
    NumberBox(int _x, int _y, int _sx, int _sy);

    void draw() override;
};

#endif // NUMBERBOX_HPP
