#ifndef LEGORDULOWIDGET_HPP
#define LEGORDULOWIDGET_HPP

#include "widget.hpp"
#include "graphics.hpp"
#include <string>

class LegorduloWidget : public Widget
{
protected:
    std::vector<std::string> options;
public:
    LegorduloWidget(int x, int y, int sx, int sy, App *parent);

    void draw() const override;
    void handle(genv::event ev) override;
};

#endif // LEGORDULOWIDGET_HPP
