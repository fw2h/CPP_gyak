#include "priorsor.h"

using namespace std;


size_t PrQueue::maxSearch() const
{
    if (isEmpty()) //std::exception -> what()
        throw EMPTY_PRQUEUE;

    size_t ind = 0;
    int max = _vec[0].pr;
    for ( size_t i = 1; i < _vec.size(); ++i)
    {
        if (_vec[i].pr > max)
        {
            ind = i;
            max = _vec[i].pr;
        }
    }
}


void PrQueue::setEmpty()
{
    //_vec = vector();
    _vec.clear();
}

bool PrQueue::isEmpty() const
{
    return _vec.size() == 0;
}

void PrQueue::add(const Item& elem)
{
    _vec.push_back(elem);
}

Item PrQueue::getMax() const
{
    size_t ind = maxSearch();
    return _vec[ind];
}

Item PrQueue::remMax()
{
    size_t ind = maxSearch();
    Item e = _vec[ind];
    _vec[ind] = _vec[_vec.size() - 1];
    _vec.pop_back();
    return e;

}

//void operator+=(const Item& e)
//{
//    _vec.add(e);
//}
