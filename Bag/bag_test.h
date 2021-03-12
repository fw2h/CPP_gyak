#ifndef BAG_TEST_H_INCLUDED
#define BAG_TEST_H_INCLUDED
#include <vector>
# include "bag.h"

class Bag_Test : public Bag
{
public:
    std::vector<Item> getItems() const { return _vec; }
    int getMaxind() const {return _maxind; }
};


#endif // BAG_TEST_H_INCLUDED
