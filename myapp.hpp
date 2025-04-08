#ifndef MYAPP_HPP
#define MYAPP_HPP

#include "app.hpp"
#include <string>

class myApp : public App
{
public:
    myApp(int szelesseg, int magassag);

    Widget* selectWidget(int mx, int my);

    void action(std::string) override;
    void event_loop() override;
};

#endif // MYAPP_HPP
