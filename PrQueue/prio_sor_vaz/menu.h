#pragma once
#include "priorsor.h"

class Menu
{
    public:
        Menu() {}

        void run();

    private:
        PrQueue pq;

        int selectMenu();

        void putIn();
        void removeMax();
        void getMax();
        void checkEmpty();
        void print();
        void test();
};
