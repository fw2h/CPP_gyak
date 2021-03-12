#include <iostream>
#include <fstream>
#include <vector>
#include "point.h"
#include "circle.h"

using namespace std;


int closestPoint(const Circle& k, const vector<Point>& x)
{
    double min_dist = 0;
    int min_ind = -1;

    for (size_t i = 0; i < x.size(); ++i)
    {
        if(!(k.contains(x[i])))
        {
            if(min_ind == -1)
            {
                min_ind = i;
                min_dist = k.getCenter().distance(x[i]);
            }
            else
            {
                int curr_dist = k.getCenter().distance(x[i]);
                if(curr_dist < min_dist)
                {
                    min_dist = curr_dist;
                    min_ind = i;
                }
            }
        }
    }
    return min_ind;
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

    int ind = closestPoint(c, t);
    if(ind >= 0) cout << t[ind].x << " " << t[ind].y <<endl;
    else cout << "Nincs megfelelo pont" <<endl;

    return 0;
}
