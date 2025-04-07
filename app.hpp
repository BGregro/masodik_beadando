#ifndef APP_HPP
#define APP_HPP

#include "widget.hpp"
#include <vector>
#include <string>

class App
{
public:
    App(int, int);

    void addWidget(Widget*);
    virtual void action(std::string) = 0;
    virtual void event_loop() = 0;

protected:
    int szelesseg, magassag;
    std::vector<Widget*> widgets;
};

#endif // APP_HPP
