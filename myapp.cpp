#include "myapp.hpp"
#include "graphics.hpp"
#include "numberbox.hpp"
#include <string>

using namespace genv;
using namespace std;

myApp::myApp(int szelesseg, int magassag):
    App(szelesseg, magassag)
{
    // ezeket hova rakjam így?
    new NumberBox(50, 50, 0, 99999999, this);
    new NumberBox(50, 100, -1000000, 1000000, this);

    for (Widget * wg : widgets)
        wg->draw();

    gout << refresh;
}

void myApp::event_loop()
{
    event ev;
    int focus = -1;

    while(gin >> ev)
    {
        if (ev.type == ev_mouse && ev.button==btn_left)
        {
            for (int i = 0; i < widgets.size(); ++i)
            {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                    focus = i;
            }
        }

        if (focus != -1)
            widgets[focus]->handle(ev);

        for (Widget *w: widgets)
            w->draw();

        // actionoket itt kezelni -> action(id)

        gout << refresh;
    }
}

void myApp::action(string id)
{

}
