#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

int hanyszor(const vector<double> &x);
int most_frequent(const vector<int> &x);

int main()
{
//    int x, y, z;
//    cout <<'X: '; cin >> x;
//    cout <<'Y: '; cin >> y;
//    z = 0;
//    for (int i = 0; i <=x; ++i) {z = z + y;}
//    cout << 'Z: ' << z <<endl;

//    ifstream input("input.txt");
//    if (input.fail()){
//        cout << "hibaa megnyitaskor";
//        return 1;}
//
//    vector<double> x;
//
//    double elem;
//    while (input >>elem){
//        x.push_back(elem);
//    }
//
//    double ertek = abs(x[0]);
//    size_t ind = 0;
//
//    for (size_t i = 1; i < x.size(); ++i){
//        double absz = abs(x[i]);
//        if (absz > ertek){
//            ertek = absz;
//            ind = i;
//        }
//    }
//
//    cout << "Maximum abszolut ertek: " << x[ind] << endl;
//    cout << "Maximum index: " << ind << endl;input.close();


    ifstream input("input.txt");
    if (input.fail()){
        cout << "hibaa megnyitaskor";
        return 1;}

    vector<int> x;

    int elem;
    while (input >>elem){
        x.push_back(elem);
    }

    int leggy = most_frequent(x);
    cout << leggy;



    return 0;
}

int most_frequent(const vector<int> &x)
{

}
