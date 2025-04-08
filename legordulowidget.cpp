#include "legordulowidget.hpp"
#include "graphics.hpp"
#include <string>

using namespace genv;
using namespace std;

const color black(0,0,0), grey(200,200,200), white(255,255,255);
const int padding = 3;

int maxTextWidth(vector<string> v)
{
    int maxW = 0;
    for (string s: v)
    {
        int sW = gout.twidth(s);
        if (sW > maxW)
            maxW = sW;
    }

    return maxW;
}

LegorduloWidget::LegorduloWidget(App *parent, int x, int y, vector<string> _options):
    Widget(parent, x, y, 0, 0), options(_options)
{
    if (_options.size() == 0)
        options.push_back("Error: No Options Given");

    selectedIndex = 0;
    hoverIndex = -1;
    opened = false;

    int maxW = maxTextWidth(options);
    arrowW = 20;
    arrowH = gout.cascent() + gout.cdescent() + padding;
    // sx a legszelesebb szoveg szelessege lesz, hogy beleferjen
    sx = maxW + arrowW + 2*padding;
    arrowX = x + sx - arrowW;
    sy = gout.cascent() + gout.cdescent() + padding;
    textH = gout.cascent() + gout.cdescent() + padding;
}

void LegorduloWidget::draw() const
{
    gout << white
         << move_to(x, y)
         << box(sx, sy);

    int textY = y + padding;

    if (opened)
    {
        gout << grey
             << move_to(x, textY-padding + hoverIndex*textH)
             << box(sx, textH);

        for (string op: options)
        {
            gout << black
                 << move_to(x + padding, textY)
                 << text(op);

            textY += textH;
        }
    }
    else
    {
        // draw selected option
        gout << black
             << move_to(x + padding, textY)
             << text(options[selectedIndex]);
    }

    // arrow background
    gout << grey
         << move_to(arrowX, y)
         << box(arrowW, arrowH);

    // down arrow
    int arrowCenterX = x + sx - arrowW/2;
    int arrowTop = y + arrowH/4;
    int arrowBottom = y + 3*arrowH/4;

    gout << black
         << move_to(arrowCenterX, arrowBottom)
         << line_to(arrowCenterX - arrowW/3, arrowTop)
         << line_to(arrowCenterX + arrowW/3, arrowTop)
         << line_to(arrowCenterX, arrowBottom);

}

void LegorduloWidget::clear_draw() const
{
    gout << black << move_to(x, y) << box(sx, sy);
}

void LegorduloWidget::open_menu()
{
    opened = true;
    sy *= options.size();
}

void LegorduloWidget::close_menu()
{
    opened = false;
    clear_draw();
    sy /= options.size();
}

void LegorduloWidget::arrowPressed(int mx, int my)
{
    if (mx >= arrowX && mx <= x+sx &&
        my >= y && my <= y+arrowH)
    {
        if (opened)
            close_menu();
        else
            open_menu();
    }
}

void LegorduloWidget::selectOption(int mx, int my)
{
    if (mx >= x && mx <= x + sx &&
        my >= y && my <= y + sy)
    {
        selectedIndex = (my-y) / textH;
        close_menu();
    }
}

void LegorduloWidget::hoverOption(int mx, int my)
{
    if (mx >= x && mx <= x + sx &&
        my >= y && my <= y + sy)
        hoverIndex = (my-y) / textH;
}

void LegorduloWidget::handle(event ev)
{
    if (ev.type == ev_mouse)
    {
        if (ev.button == btn_left)
        {
            if (opened)
                selectOption(ev.pos_x, ev.pos_y);

            arrowPressed(ev.pos_x, ev.pos_y);

        }

        if (opened)
            hoverOption(ev.pos_x, ev.pos_y);

    }
}


