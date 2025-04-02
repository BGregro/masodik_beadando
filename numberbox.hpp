#ifndef NUMBERBOX_HPP
#define NUMBERBOX_HPP

#include "widget.hpp"
#include "graphics.hpp"

class NumberBox : public Widget
{
protected:
    int ertek, minErtek, maxErtek;
public:
    NumberBox(int x, int y, int sx, int sy, int minErtek, int maxErtek);

    void draw() const override;
    void handle(genv::event event) override;

    void setNum(int newNum);
    void novelNum();
    void csokkentNum();
};

#endif // NUMBERBOX_HPP

/*
TODO:
 * belekattintas -> a végére lehessen írni és egérrel mozgatni a cursort? (megkérdezni gyakvezt)
    * sima cursor legyen benne? (pl belekattintaskor megjelenik és a szám végén van mindig)
 * max és min. num, hogy ne menjen ki az int határból
 * negatív számok beírásakot -> külön érzékelni, hogy a minusz gomb meg lett nyomba és úgy kezelni
    * is_negative bool -> mező?
 * egyéb grafikai szépítések: border, szebb gombok
 * Max/Min: így működjön, vagy ha nagyobb/kisebb lenne a szám, akkor ne lehessen többet írni?
*/
