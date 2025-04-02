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

    NumberBox *nb1 = new NumberBox(50, 100, 100, 50, 0, 1000000);
    NumberBox *nb2 = new NumberBox(200, 100, 100, 50, -500000, 500000);

    vector<Widget*> widgets;
    widgets.push_back(nb1);
    widgets.push_back(nb2);

    gout << refresh;

    event ev;
    int focus = -1;

    while(gin >> ev)
    {
        if (ev.type == ev_mouse && ev.button==btn_left)
        {
            for (size_t i=0;i<widgets.size();i++)
            {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                }
            }
        }

        //cout << ev.keycode << " " << ev.keyname << " " << ev.keyutf8 << endl;

        if (focus!=-1)
        {
            widgets[focus]->handle(ev);
        }

        for (Widget * w : widgets)
        {
            w->draw();
        }

        gout << refresh;
    }

    return 0;
}

/*
Ötletek:
 * void select_widget(int mx, int my); function egér kattintás kezelésére
*/
