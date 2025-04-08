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

    vector<string> pelda0 = {"option0", "option1", "option2", "option3"};
    new LegorduloWidget(this, 50, 150, pelda0);

    vector<string> pelda1;
    new LegorduloWidget(this, 50, 200, pelda1);

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
    Widget *focus = 0;

    while(gin >> ev)
    {
        if (ev.type == ev_mouse && ev.button == btn_left)
        {
            focus = selectWidget(ev.pos_x, ev.pos_y);
        }

        for (Widget *w: widgets)
            w->draw();

        // TODO: megcsinálni, hogy a kiválasztott widget draw-oljon felülre mindig
        if (focus != 0)
        {
            focus->handle(ev);
            focus->draw();
        }

        // actionoket itt kezelni -> action(id)

        gout << refresh;
    }
}

// ebbe file írás és még mi?
void myApp::action(string id)
{

}
