#pragma once
#include <iostream>
#include <vector>
#include "complex.h"

class Menu
{
    public:
        Menu(){}
        void run();

    private:
        std::vector<Complex> vec;

        int selectMenu();

        void addNew();
        void listNums();

        void addition();
        void subtraction();
        void multiplication();
        void division();
        void conjugation();

};
