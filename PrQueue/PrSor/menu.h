//K�sz�tette:    Veszpr�mi Anna
//D�tum:         2018.02.20.
//Men�rendszer header �llom�ny

#pragma once

#include "priorsor.h"

class Menu
{
    public:
        Menu(){};
        void run();
    private:
        int  getMenuPoint();
        void putIn();
        void removeMax();
        void getMax();
        void checkEmpty();
        void write();
        void test();
        PrQueue pq;

};
