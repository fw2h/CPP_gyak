#include "bag.h"
#include <iostream>

using namespace std;


void Bag::clear()
{
    _vec.clear();
    _maxind = 0;
}

void Bag::putIn(int e)
{
    size_t ind;
    if (logSearch(e, ind))
    {
        ++_vec[ind].count;
        if (_vec[ind].count > _vec[_maxind].count)
            _maxind = ind;
    }
    else
    {
        _vec.insert(_vec.begin() + ind, Item(e, 1));
        if (_maxind >= ind && _vec.size() > 1)
            ++_maxind;
    }
}

void Bag::takeOut(int e)
{
    size_t ind;
    if (logSearch(e, ind))
    {
        if (_vec[ind].count > 1)
            --_vec[ind].count;
        else _vec.erase(_vec.begin() + ind);
        _maxind = _vec.size() > 0 ? maxSearch() : 0;
    }
    //else throw NOT_IN_BAG;
}

int Bag::mostFrequent() const
{
    if (_vec.size() == 0)
		throw EMPTY_BAG;
    return _vec[_maxind].value;
}


size_t Bag::maxSearch() const
{
    if (_vec.size() == 0)
        throw EMPTY_BAG;

    size_t max =_vec[0].count;
    size_t ind = 0;
    for (size_t i = 1; i < _vec.size(); ++i)
    {
        if (_vec[i].count > max)
        {
            max = _vec[i].count;
            ind = i;
        }
    }
    return ind;
}

bool Bag::logSearch(int e, size_t &index) const
{
    bool l = false;
    int ah = 0;
    int fh = _vec.size() -1;
    while(!l && ah <= fh)
    {
        index = (ah + fh) / 2;
        if (_vec[index].value > e)
            fh = index -1;
        else if (_vec[index].value < e)
            ah = index + 1;
        else
            l = true;

    }
    if(!l)
        index = ah;
    return l;

}
