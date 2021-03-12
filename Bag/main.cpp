#include <iostream>
#include <fstream>
#include "bag.h"



using namespace std;

#define NORMAL_MODE1
#ifdef NORMAL_MODE
int main()
{
    ifstream f("input.txt");
    if (f.fail())
	{
        cerr << "File open error!" << endl;
        return 1;
    }

    Bag b;
    int e;
    while (f >> e)
    {
        cout << "Putting in " << e << endl;
		b.putIn(e);
    }

	try
	{
        cout << "The most frequent element is " << b.mostFrequent() << endl;
	}
	catch (Bag::Error e)
    {
        if (e == Bag::EMPTY_BAG)
            cerr << "Empty bag." << endl;
        else cerr << "Unknown error." << endl;
    }
    return 0;
}

#else

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "bag_test.h"

TEST_CASE("Leggyakoribb a 2", "[Bag][MostFrequent]")
{
    Bag b;
    b.putIn(2);
    CHECK(b.mostFrequent() == 2);
}

TEST_CASE("Leggyakoribb nincs", "[Bag][MostFrequent]")
{
    Bag b;
    CHECK_THROWS(b.mostFrequent());
}

TEST_CASE("Leggyakoribb nem egyertelmu", "[Bag][MostFrequent]")
{
    ifstream test("test1.txt");
    REQUIRE(!test.fail());
    Bag b;
    int e;
    while(test >> e)
        b.putIn(e);
    bool l = b.mostFrequent() == 2 || b.mostFrequent() == 3;
    CHECK(l);
//    CHECK_THROWS(b.mostFrequent());
}

TEST_CASE("Sorrend jo", "[Bag]")
{
    Bag_Test b;
    b.putIn(2);
    b.putIn(1);
    vector<Item> v = b.getItems();
    CHECK(v[0].value == 1);
    CHECK(v[1].value == 2);
//    CHECK_THROWS(b.mostFrequent());
}

TEST_CASE("maxelem jo", "[Bag]")
{
    Bag_Test b;
    b.putIn(2);
    b.putIn(1);
    b.putIn(4);
    b.putIn(3);
    int v = b.getMaxind();
    CHECK(v == 1);
//    CHECK_THROWS(b.mostFrequent());
}

TEST_CASE("tobb maxelem jo", "[Bag]")
{
    Bag_Test b;
    b.putIn(2);
    b.putIn(1);
    b.putIn(4);
    b.putIn(3);
    b.putIn(4);
    b.putIn(3);
    int v = b.getMaxind();
    CHECK(v == 3);
//    CHECK_THROWS(b.mostFrequent());
}

TEST_CASE("clear jo", "[Bag]")
{
    Bag_Test b;
    b.putIn(2);
    b.putIn(1);
    b.putIn(4);
    b.clear();
    CHECK_THROWS(b.mostFrequent());
}
#endif
