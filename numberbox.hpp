#ifndef NUMBERBOX_HPP
#define NUMBERBOX_HPP

#include "widget.hpp"

class NumberBox : public Widget
{
protected:
    int ertek, minErtek, maxErtek;
    int arrowX, arrowW, arrowH; // arrow buttons
    bool isNegative;
public:
    NumberBox(int _x, int _y, int _sx, int _sy, int _minErtek, int _maxErtek, App *parent);

    void draw() const override;
    void handle(genv::event event) override;

    void arrowPressed(int mx, int my);
    void setNum(int newNum);
    void novelNum();
    void csokkentNum();
};

#endif // NUMBERBOX_HPP

/*
TODO:
 * bug: tele 9-essel valamit csinál
 * kitörölni rendesen, amikor nincs benne érték?
    * pl 0-val jelenjen meg, de amikor belekattintok, akkor tűnjön el (+ amikor odáig törlök, akkor is)
 * belekattintas -> a végére lehessen írni és egérrel mozgatni a cursort? (megkérdezni gyakvezt)

 * negatív számok beírásakot -> külön érzékelni, hogy a minusz gomb meg lett nyomba és úgy kezelni
    * is_negative bool -> mező?

 * egyéb grafikai szépítések: border, szebb gombok (gomb hover)
 * külön tárolni a fel/le gombok helyét és külön check-elni, hogy azokra lett-e kattintva (külön fv)
*/
