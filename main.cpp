#include <iostream>
#include "graphics.hpp"
#include "widget.hpp"
#include "numberbox.hpp"

using namespace std;
using namespace genv;

const int szelesseg = 600, magassag = 600;


int main()
{
    gout.open(szelesseg, magassag);

    NumberBox nb1(50, 100, 100, 50);
    nb1.draw();

    gout << refresh;

    event ev;
    while(gin >> ev)
    {
    }

    return 0;
}

/*
Ötletek:
 * void select_widget(int mx, int my); function egér kattintás kezelésére
*/
