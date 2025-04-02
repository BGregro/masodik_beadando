#include "numberbox.hpp"
#include "graphics.hpp"
#include <string>
#include <iostream>

using namespace genv;
using namespace std;

const color black(0,0,0), grey(200,200,200);
const int defaultMin = 0, defaultMax = 100000;
const int padding = 5;

NumberBox::NumberBox(int _x, int _y, int _sx, int _sy, int _minErtek, int _maxErtek):
    Widget(_x, _y, _sx, _sy), minErtek(_minErtek), maxErtek(_maxErtek)
{
    arrowW = 30;
    arrowH = sy/2;

    // ha a widget-be nem ferne bele a max szam
    int numW = gout.twidth("1");
    int maxNumW = numW*(to_string(maxErtek).size()+1); // +1, hogy a negativ szamokkal se legyen gond
    if (maxNumW + arrowW > sx)
        sx = maxNumW + arrowW + padding;

    arrowX = x + sx - arrowW;

    // ha rosszul van megadva a min/max a konstruktorban
    if (minErtek > maxErtek)
    {
        cout << "invalid min/max value: using default values" << endl;
        minErtek = defaultMin;
        maxErtek = defaultMax;
    }

    // ha a 0 nincs benne az intervallumban
    if (minErtek > 0)
        ertek = minErtek;
    else if (maxErtek < 0)
        ertek = maxErtek;
    else
        ertek = 0;

}

void NumberBox::draw() const
{
    // Draw main box background (number area + arrows)
    gout << color(255, 255, 255) << move_to(x, y) << box(sx, sy);

    int numH = gout.cascent();
    // Draw number (centered vertically, left-aligned with padding)
    gout << color(255, 0, 0)
         << move_to(x + padding, y + sy/2 - numH/2)
         << text(to_string(ertek));

    // Draw cursor if it fits in number area
    int numW = gout.twidth("1");
    int cursorX = x + padding + to_string(ertek).size() * numW;
    if (cursorX < x + numW*to_string(ertek).size())
    {
        gout << black
             << move_to(cursorX, y + padding)
             << line(0, sy - 2*padding);
    }

    // background for arrows
    gout << grey
         << move_to(arrowX, y)
         << box(arrowW, arrowH*2);

    // Draw up arrow button (top right)
    gout << black
         << move_to(arrowX + arrowW/2, y + padding)
         << line_to(arrowX + arrowW - padding, y + arrowH - padding)
         << line_to(arrowX + padding, y + arrowH - padding)
         << line_to(arrowX + arrowW/2, y + padding);

    // separator line
    gout << black
         << move_to(arrowX, y + arrowH)
         << line_to(arrowX + arrowW, y + arrowH);

    // Draw down arrow button (bottom right)
    gout << black
         << move_to(arrowX + arrowW/2, y + sy - padding)
         << line_to(arrowX + arrowW - padding, y + arrowH + padding)
         << line_to(arrowX + padding, y + arrowH + padding)
         << line_to(arrowX + arrowW/2, y + sy - padding);
}

void NumberBox::arrowPressed(int mx, int my)
{
    if (mx > arrowX && mx < x+sx)
    {
        if (my > y && my < y+sy/2)
            novelNum();
        else if (my > y+sy/2 && my < y+sy)
            csokkentNum();
    }
}

void NumberBox::handle(event ev)
{
    if (ev.type == ev_mouse && ev.button == btn_left)
    {
        arrowPressed(ev.pos_x, ev.pos_y);
    }
    else if (ev.type == ev_key && ev.keycode > 0) // key felengedésnél ne fusson le megegyszer
    {        
        if (ev.keycode == key_backspace)
            ertek = ertek/10;

        if (ertek == 0 && ev.keyname == "-") // ez igy jo?
        {
            if (minErtek < 0)
                ertek = -ertek;
        }


        if (!ev.keyutf8.empty() && ev.keyutf8.size() == 1 &&
            ev.keyutf8[0] >= '0' && ev.keyutf8[0] <= '9')
        {
            // beírt szám beállítása -> erre külön fv.?
            int number = ev.keyutf8[0] - '0';
            if (ertek*10 + number < maxErtek
                && ertek*10 + number > minErtek)
            {
                ertek = ertek*10 + number;
            }
        }
    }

}

void NumberBox::setNum(int newNum)
{
    ertek = newNum;
}

void NumberBox::novelNum()
{
    if (ertek < maxErtek)
        ++ertek;
}

void NumberBox::csokkentNum()
{
    if (ertek > minErtek)
        --ertek;
}





