#ifndef LEGORDULOWIDGET_HPP
#define LEGORDULOWIDGET_HPP

#include "widget.hpp"
#include "graphics.hpp"
#include <string>

class LegorduloWidget : public Widget
{
protected:
    std::vector<std::string> options;
    int selectedIndex;
    int arrowX, arrowW;
public:
    LegorduloWidget(App *parent, int x, int y, std::vector<std::string> _options);

    void arrowPressed(int mx, int my);
    void draw() const override;
    void handle(genv::event ev) override;
};

#endif // LEGORDULOWIDGET_HPP
