#include "myapp.hpp"
#include "graphics.hpp"
#include "numberbox.hpp"
#include "legordulowidget.hpp"
#include <string>
#include <fstream>

using namespace genv;
using namespace std;

myApp::myApp(int szelesseg, int magassag):
    App(szelesseg, magassag)
{
    focus = 0;
    new NumberBox(this, 50, 50, 0, 99999999);
    new NumberBox(this, 50, 100, -1000000, 1000000);

    vector<string> pelda0 = {"option0", "option1", "option2", "option3", "option4", "option5", "option6"};
    new LegorduloWidget(this, 50, 150, 4, pelda0);

    vector<string> pelda1 = {"alma", "körte", "barack", "gyümölcstál"};
    new LegorduloWidget(this, 50, 200, 3, pelda1);

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
        if (ev.type == ev_mouse && ev.button == btn_left)
        {
            focus = selectWidget(ev.pos_x, ev.pos_y);
        }

        for (Widget *w : widgets)
        {
            if (w != focus)
                w->draw();
        }

        if (focus != nullptr)
        {
            focus->handle(ev);
            focus->draw();
        }

        if (ev.type == ev_key)
        {
            // action-ok kezelése
            if (ev.keycode == key_enter)
                action("enter");
        }

        gout << refresh;
    }
}

void myApp::action(string id)
{
    if (id == "enter")
    {
        ofstream outfile("kimenet.txt");

        for (Widget *w : widgets)
        {
            outfile << w->getValueString() << "\n";
        }

        outfile.close();
    }
}
