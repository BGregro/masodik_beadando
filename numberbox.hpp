#ifndef NUMBERBOX_HPP
#define NUMBERBOX_HPP

#include "widget.hpp"

class NumberBox : public Widget
{
protected:
    int ertek, minErtek, maxErtek;
    int arrowX, arrowW, arrowH; // arrow buttons
    bool isNegative;
public:
    NumberBox(App *parent, int _x, int _y, int _minErtek, int _maxErtek);

    void draw() const override;
    void handle(genv::event event) override;

    void arrowPressed(int mx, int my);
    void setNum(int newNum);
    void novelNum();
    void csokkentNum();
};

// TODO: pageUp, pageDown

#endif // NUMBERBOX_HPP
