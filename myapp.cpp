#include "myapp.hpp"
#include "graphics.hpp"
#include "numberbox.hpp"
#include "legordulowidget.hpp"
#include <string>

using namespace genv;
using namespace std;

myApp::myApp(int szelesseg, int magassag):
    App(szelesseg, magassag)
{
    // ezeket hova rakjam így?
    new NumberBox(this, 50, 50, 0, 99999999);
    new NumberBox(this, 50, 100, -1000000, 1000000);

    vector<string> pelda1;
    new LegorduloWidget(this, 50, 150, pelda1);

    for (Widget * wg : widgets)
        wg->draw();

    gout << refresh;
}

Widget* myApp::selectWidget(int mx, int my)
{
    for (int i = 0; i < widgets.size(); ++i)
    {
        if (widgets[i]->is_selected(mx, my))
            return widgets[i];
    }

    return 0;
}

void myApp::event_loop()
{
    event ev;

    while(gin >> ev)
    {
        Widget *focus = 0;
        if (ev.type == ev_mouse && ev.button == btn_left)
        {
            focus = selectWidget(ev.pos_x, ev.pos_y);
        }

        if (focus != 0)
            focus->handle(ev);

        for (Widget *w: widgets)
            w->draw();

        // actionoket itt kezelni -> action(id)

        gout << refresh;
    }
}

void myApp::action(string id)
{

}
