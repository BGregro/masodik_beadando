#include "app.hpp"
#include "widget.hpp"
#include "graphics.hpp"
#include <vector>

using namespace genv;
using namespace std;

App::App(int _szelesseg, int _magassag):
    szelesseg(_szelesseg), magassag(_magassag)
{
    gout.open(szelesseg, magassag);
}

void App::addWidget(Widget* w)
{
    widgets.push_back(w);
}
