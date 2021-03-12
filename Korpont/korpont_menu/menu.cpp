#include "menu.h"

using namespace std;


void Menu::run()
{
    // menupontok bekerese es a megfelelo menupont futtatasa
    cout << "=== Kor es Pont ===" << endl;
    bool run = true;
    while (run)
    {
        int m = selectMenu();
        switch (m)
        {
        case 0:
            run = false;
            break;
        case 1:
            addPoint();
            break;
        case 2:
            removePoint();
            break;
        case 3:
            changeCircle();
            break;
        case 4:
            findPoint();
            break;
        }
    }
    cout << "=== Viszontlatasra! ===" << endl;
}


int Menu::selectMenu() const
{
    // menuinfo kiirasa
    cout << endl;
    cout << "Menu lehetosegek:" << endl;
    cout << "0 - kilepes" << endl;
    cout << "1 - pont felvetele" << endl;
    cout << "2 - pont torlese" << endl;
    cout << "3 - kor modositasa" << endl;
    cout << "4 - belso pont keresese" << endl;

    // valasztott menupont bekerese
    cout << "Menu: ";
    int m;
    cin >> m;
    while (m < 0 || m > 4)
    {
        cerr << "Ervenytelen valasztas." << endl;
        cout << "Menu: ";
        cin >> m;
    }
    cout << endl;
    return m;
}

void Menu::addPoint()
{
    // uj pont bekerese konzolbol
    double x, y;
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;

    // hozzaadas
    ps.push_back(Point(x, y));
    cout << "Pont hozzaadva." << endl;
}

void Menu::removePoint()
{
    // torlendo pont bekerese konzolbol
    double x, y;
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;

    // pont keresese koordinatak alapjan
    size_t ind;
    bool l = false;
    for (size_t i = 0; !l && i < ps.size(); ++i)
    {
        l = ps[i].x == x && ps[i].y == y;
        ind = i;
    }

    if (l)
    {
        // pont torlese
        ps.erase(ps.begin() + ind);
        cout << "Pont eltavolitva." << endl;
    }
    else cerr << "Nem volt ilyen pont." << endl;
}

void Menu::changeCircle()
{
    // kor bekerese konzolbol
    double x, y, r;
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    cout << "Radius: ";
    cin >> r;

    // kor lecserelese az ujra
    c = Circle(Point(x, y), r);
}

void Menu::findPoint()
{
    // belso pont keresese
    size_t ind;
    bool l = false;
    for (size_t i = 0; !l && i < ps.size(); ++i)
    {
        l = c.contains(ps[i]);
        ind = i;
    }

    // eredmény kiiratasa
    if (l)
        cout << "A (" << ps[ind].x << "," << ps[ind].y << ") koordinataju pont a korbe esik." << endl;
    else cout << "Egyik pont sincs a korben." << endl;
}
