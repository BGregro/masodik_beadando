#include "numberbox.hpp"
#include "graphics.hpp"
#include <string>
#include <iostream>

using namespace genv;
using namespace std;

NumberBox::NumberBox(int x, int y, int sx, int sy, int _minErtek, int _maxErtek):
    Widget(x, y, sx, sy), minErtek(_minErtek), maxErtek(_maxErtek)
{
    ertek = 0;
}

void NumberBox::draw() const
{
    gout.load_font("LiberationMono-Regular.ttf", 20);

    gout << color(255, 255, 255) << move_to(x, y) << box(sx, sy)
         << color(255,0,0) << move_to(x+5, y+sy/2) << text(to_string(ertek));

    /* draw cursor */
    int numW = gout.twidth("1");
    gout << color(0,0,0) << move_to(x+5 + to_string(ertek).size()*numW, y+5)
         << line(0, sy-10);
}

void NumberBox::handle(event ev)
{
    if (ev.type == ev_key && ev.keycode > 0) // key felengedésnél ne fusson le megegyszer
    {
        if (ev.keycode == key_backspace)
            ertek = ertek/10;

        if (!ev.keyutf8.empty() && ev.keyutf8.size() == 1 &&
            ev.keyutf8[0] >= '0' && ev.keyutf8[0] <= '9')
        {
            int number = ev.keyutf8[0] - '0';
            if (ertek*10 + number > maxErtek) // így?
                ertek = maxErtek;
            else if (ertek*10 + number < minErtek)
                ertek = minErtek;
            else
                ertek = ertek*10 + number;
        }
    }

}

void NumberBox::setNum(int newNum)
{
    ertek = newNum;
}

void NumberBox::novelNum() { ++ertek; }

void NumberBox::csokkentNum() { --ertek; }
