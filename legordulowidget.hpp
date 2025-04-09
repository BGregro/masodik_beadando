#ifndef LEGORDULOWIDGET_HPP
#define LEGORDULOWIDGET_HPP

#include "widget.hpp"
#include "graphics.hpp"
#include <string>

class LegorduloWidget : public Widget
{
protected:
    std::vector<std::string> options;
    int textH, selectedIndex, hoverIndex;
    int arrowX, arrowW, arrowH;
    bool opened;
public:
    LegorduloWidget(App *parent, int x, int y, std::vector<std::string> _options);

    void draw() const override;
    void handle(genv::event) override;

    void hoverOption(int mx, int my);
    void selectOption(int mx, int my);
    void arrowPressed(int mx, int my);
    void open_menu();
    void close_menu();
    void clear_draw() const;
};

// TODO: nyíl működjön mindig, a kivalasztott opcio legyen felül akkor is, amikor legordul
// TODO: kovetelmenyek alapjan gorgetheto legyen a menu es meg lehessen adni a meretet (es min/max meretet meg lehessen adni)
/*
Ötletek
 * option hover? -> szürkére változik a háttere, amikor hover-oli (amikor le van nyitva)
 */

#endif // LEGORDULOWIDGET_HPP
