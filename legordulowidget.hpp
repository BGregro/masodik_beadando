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
    int arrowX, arrowW, arrowH;
    bool opened;
public:
    LegorduloWidget(App *parent, int x, int y, std::vector<std::string> _options);

    void draw() const override;
    void handle(genv::event) override;
    void selectOption(int mx, int my);

    void arrowPressed(int mx, int my);
    void clear_draw() const;
};

/*
Ötletek
 * option hover? -> szürkére változik a háttere, amikor hover-oli (amikor le van nyitva)
 */

#endif // LEGORDULOWIDGET_HPP
