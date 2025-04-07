#include <iostream>
#include "myapp.hpp"

using namespace std;
using namespace genv;

int main()
{
    gout.load_font("LiberationMono-Regular.ttf", 20); // ezt hova tegyem?
    myApp app(600,600);
    app.event_loop();

    return 0;
}

/*
Ötletek:
 * void select_widget(int mx, int my); function egér kattintás kezelésére
*/
