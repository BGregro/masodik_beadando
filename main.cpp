#include <iostream>
#include "myapp.hpp"

using namespace std;
using namespace genv;

int main()
{
    myApp app(600,600);
    app.event_loop();

    return 0;
}
