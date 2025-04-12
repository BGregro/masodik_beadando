#include "numberbox.hpp"
#include "graphics.hpp"
#include <string>
#include <iostream>

using namespace genv;
using namespace std;

const color black(0,0,0), grey(200,200,200), white(255,255,255);
const int defaultMin = 0, defaultMax = 100000;
const int padding = 3;

NumberBox::NumberBox(App *parent, int _x, int _y, int _minErtek, int _maxErtek):
    Widget(parent, _x, _y, 0, 0), minErtek(_minErtek), maxErtek(_maxErtek)
{
    isNegative = false;

    // a widget meretei a szoveg meretei alapjan kiszamolva
    int numW = gout.twidth("1"), numH = gout.cascent();
    int maxNumW = numW*(to_string(maxErtek).size()+1); // +1, hogy a negativ szamok se logjanak ki
    arrowW = 20;
    sx = maxNumW + arrowW + padding;
    sy = numH + 4*padding;
    arrowH = sy/2;

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
    gout << white << move_to(x, y) << box(sx, sy);


    int numH = gout.cascent();
    int numW = gout.twidth("1");

    if (isNegative)
    {
        gout << black
             << move_to(x+padding, y + sy/2 - numH/2)
             << text("-")
             << move_to(x+padding + numW, y + sy/2 - numH/2)
             << text(to_string(abs(ertek)));

        // draw cursor
        gout << black
             << move_to(x+padding + (to_string(abs(ertek)).size()+1)*numW, y+padding)
             << line(0, sy-padding*2);
    }
    else
    {
        gout << black
             << move_to(x+padding, y + sy/2 - numH/2)
             << text(to_string(ertek));

        // draw cursor
        gout << black
             << move_to(x+padding + to_string(ertek).size()*numW, y+padding)
             << line(0, sy-padding*2);
    }

    // arrow background
    gout << grey
         << move_to(arrowX, y)
         << box(arrowW, arrowH*2);

    // up arrow
    gout << black
         << move_to(arrowX + arrowW/2, y + padding)
         << line_to(arrowX + arrowW - padding, y + arrowH - padding)
         << line_to(arrowX + padding, y + arrowH - padding)
         << line_to(arrowX + arrowW/2, y + padding);

    // separator line
    gout << black
         << move_to(arrowX, y + arrowH)
         << line_to(arrowX + arrowW, y + arrowH);

    // down arrow
    gout << black
         << move_to(arrowX + arrowW/2, y + sy - padding)
         << line_to(arrowX + arrowW - padding, y + arrowH + padding)
         << line_to(arrowX + padding, y + arrowH + padding)
         << line_to(arrowX + arrowW/2, y + sy - padding);
}

void NumberBox::arrowPressed(int mx, int my)
{
    if (mx >= arrowX && mx <= x+sx)
    {
        if (my >= y && my <= y+sy/2)
            novelNum();
        else if (my > y+sy/2 && my <= y+sy)
            csokkentNum();
    }
}

void NumberBox::handle(event ev)
{
    if (ev.type == ev_mouse && ev.button == btn_left)
    {
        arrowPressed(ev.pos_x, ev.pos_y);
        if (ertek < 0)
            isNegative = true;
        else
            isNegative = false;
    }
    else if (ev.type == ev_key && ev.keycode > 0) // key felengedesenel ne fusson le megegyszer
    {        
        if (ev.keycode == key_backspace)
        {
            ertek = ertek/10;
            if (ertek == 0) // ha 1 szamjegy van es torlunk, akkor vegye le a "-" jelet
                isNegative = false;
        }
        else if (ev.keycode == key_pgdn && ertek-10 > minErtek)
            ertek -= 10;
        else if (ev.keycode == key_pgup && ertek+10 < maxErtek)
            ertek += 10;


        // negativ beallitasa, ha meg nem irtunk semmit
        if (ertek == 0 && ev.keyname == "-" && minErtek < 0)
            isNegative = !isNegative;

        // szam beirasa a widgetbe
        if (!ev.keyutf8.empty() && ev.keyutf8.size() == 1 &&
            ev.keyutf8[0] >= '0' && ev.keyutf8[0] <= '9')
        {
            // beirt szam beallitasa
            int number = ev.keyutf8[0] - '0';
            setErtek(ertek*10 + number);
        }
    }
}

void NumberBox::setErtek(int ujErtek)
{
    if (ertek <= maxErtek && ertek >= minErtek )
        ertek = ujErtek;
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

int NumberBox::getErtek() const
{
    return ertek;
}

string NumberBox::getValueString() const
{
    return to_string(ertek);
}




