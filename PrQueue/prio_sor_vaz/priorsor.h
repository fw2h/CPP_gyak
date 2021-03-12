#pragma once
#include <iostream>
#include <vector>


struct Item
{
    int pr;
    std::string data;

    Item() {}
    Item(int p, std::string s) : pr(p), data(s) {}
};

class PrQueue
{
public:
    enum Exception{EMPTY_PRQUEUE};

    private:
        std::vector<Item> _vec;
        size_t maxSearch() const;

    public:
        size_t size() const { return _vec.size(); }
        size_t capacity() const { return _vec.capacity(); }

        void setEmpty();
        bool isEmpty() const;
        void add(const Item& elem);
        Item getMax() const;
        Item remMax();

        void operator+=(const Item& e);
};
