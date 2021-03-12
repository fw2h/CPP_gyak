#pragma once
#include <vector>


struct Item
{
    int value;
    size_t count;

    Item(int val, size_t cnt) : value(val), count(cnt) {}
};

class Bag
{
public:
    enum Error
	{
		EMPTY_BAG,
		NOT_IN_BAG
	};

	Bag() : _vec(), _maxind(0) {}

	size_t size() const { return _vec.size(); }

    void clear();
    void putIn(int e);
    void takeOut(int e);
    int mostFrequent() const;

protected:
    std::vector<Item> _vec;
    size_t _maxind;

private:
	bool logSearch(int e, size_t &index) const;
	size_t maxSearch() const;
};

