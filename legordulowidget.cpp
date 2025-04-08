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

    int maxW = maxTextWidth(options);
    arrowW = 20;
    sx = maxW + arrowW + 2*padding;
    arrowX = x + sx - arrowW;
    sy = gout.cascent() + gout.cdescent() + 2*padding;
}

// TODO: itt is úgy legyen beállítva a méret, hogy beleférjenek a szövegek (max szöveg mérettel)

void LegorduloWidget::draw() const
{
    gout << white << move_to(x, y) << box(sx, sy);

    // Calculate text position (vertically centered)
    int textY = y + (sy - gout.cascent() - gout.cdescent()) / 2;

    // Draw the selected option text (if any)
    if (selectedIndex >= 0 && selectedIndex < options.size())
    {
        gout << black
             << move_to(x + padding, textY)
             << text(options[selectedIndex]);
    }

    // Draw the arrow area
    gout << grey
         << move_to(arrowX, y)
         << box(arrowW, sy);

    // Draw the downward-pointing triangle
    int arrowCenterX = x + sx - arrowW/2;
    int arrowTop = y + sy/4;
    int arrowBottom = y + 3*sy/4;

    gout << black
         << move_to(arrowCenterX, arrowBottom)
         << line_to(arrowCenterX - arrowW/3, arrowTop)
         << line_to(arrowCenterX + arrowW/3, arrowTop)
         << line_to(arrowCenterX, arrowBottom);

}

void LegorduloWidget::handle(event ev)
{

}

void LegorduloWidget::arrowPressed(int mx, int my)
{

}
