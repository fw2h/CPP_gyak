#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <vector>
#include "point.h"
#include "circle.h"

// menu osztalya
class Menu
{
private:
    // tartalmazza a kort es a pontokat
    Circle c;
    std::vector<Point> ps;

public:
    Menu() : c(Point(0, 0), 1), ps() {}

    // futtatas fofuggvenye
    void run();

private:
    // segedfuggvenyek, menupontok
    int selectMenu() const;
    void addPoint();
    void removePoint();
    void changeCircle();
    void findPoint();
};

#endif // MENU_H_INCLUDED
