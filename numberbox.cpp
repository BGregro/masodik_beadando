#include "numberbox.hpp"
#include "graphics.hpp"
#include <string>

using namespace genv;
using namespace std;

NumberBox::NumberBox(int _x, int _y, int _sx, int _sy):
    Widget(_x, _y, _sx, _sy)
{
    ertek = 0;
}

void NumberBox::draw() const
{
    gout.load_font("LiberationMono-Regular.ttf", 20);

    gout << color(255, 255, 255) << move_to(x, y) << box(sx, sy)
         << color(0,0,0) << move_to(x+5, y+sy/2) << text(to_string(ertek));
}

void handle(event ev)
{
    if (ev.button == btn_left)
    {

    }
}

void NumberBox::setNum(int newNum)
{
    ertek = newNum;
}

void NumberBox::novelNum() { ++ertek; }

void NumberBox::csokkentNum() { --ertek; }
