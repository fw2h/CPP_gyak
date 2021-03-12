#include <iostream>
#include <fstream>
#include <vector>
#include "point.h"
#include "circle.h"

using namespace std;


bool findPoint(const Circle& k, const vector<Point>& x, size_t& ind)
{
    bool l = false;
    for (size_t i = 0; !l && i < x.size(); ++i)
    {
        l = k.contains(x[i]);
        ind = i;
    }
    return l;
}

int main()
{
    ifstream f("input.txt");
    if (f.fail())
	{
		cerr << "Hiba a fajl megnyitasakor!" << endl;
		return 1;
	}

    double x, y, r;
    f >> x >> y >> r;
    Circle c(Point(x, y), r);

    vector<Point> t;
    while(f >> x >> y)
        t.push_back(Point(x, y));

    size_t ind;
    if (findPoint(c, t, ind))
        cout << "A (" << t[ind].x << "," << t[ind].y << ") koordinataju pont a korbe esik." << endl;
    else cout << "Egyik pont sincs a korben." << endl;

    return 0;
}
