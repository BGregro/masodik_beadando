#ifndef NUMBERBOX_HPP
#define NUMBERBOX_HPP

#include "widget.hpp"
#include "graphics.hpp"

class NumberBox : public Widget
{
protected:
    int ertek;
public:
    NumberBox(int _x, int _y, int _sx, int _sy);

    void draw() const override;
    void handle(genv::event event) override;

    void setNum(int newNum);
    void novelNum();
    void csokkentNum();
};

#endif // NUMBERBOX_HPP

/*
Ötletek
 * ha nem volt focusban és abban lett, akkor kijelölni az összes számot és teljesen újat lehessen írni
    * ha még egyszer belekattint a user, akkor a szám végére lehessen írni
    * a szám közepére is lehessen írni?
 *
*/
