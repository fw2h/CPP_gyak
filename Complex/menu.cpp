
#include "menu.h"

using namespace std;


void Menu::run()
{
    cout << "=== Komplex szam ===" << endl;
    bool running = true;
    while (running)
	{
        int m = selectMenu();
        switch (m)
		{
        case 0:
            running = false;
            break;
        case 1:
            addNew();
            break;
        case 2:
            listNums();
            break;
        case 3:
            addition();
            break;
        case 4:
            subtraction();
            break;
        case 5:
            multiplication();
            break;
        case 6:
            division();
            break;
        case 7:
            conjugation();
            break;
        }
    }
    cout << "=== Viszontlatasra ===" << endl;
}


int Menu::selectMenu()
{
    cout << endl << "Menu opciok:" << endl;
    cout << "0. Kilepes" << endl;
    cout << "1. Uj  szam hozzaadasa" << endl;
    cout << "2. Szamok listazasa" << endl;
    cout << "3. Szamok osszeadasa" << endl;
    cout << "4. Szamok kivonasa" << endl;
    cout << "5. Szamok osszeszorzasa" << endl;
    cout << "6. Szamok osztasa" << endl;
    cout << "7. Szam konjugaltja" << endl;
    cout << endl;

	cout << "Valasztott menupont: ";
	int m;
	cin >> m;
    while (m < 0 || m > 7)
	{
		cerr << "0 es 7 kozotti szam kell: ";
		cin >> m;
	}
	return m;
}


void Menu::addNew()
{
    cout << "Az uj szam valos es kepzetes resze(szokozzel elvalasztva): " << endl;
    double x,y;
    cin >> x >> y;
    Complex n(x, y);
    vec.push_back(n);
    cout << "Az uj szam: " << n << endl;
}

void Menu::listNums()
{
    cout << "A listaban szereplo szamok: " << endl;
    for(int i = 0; i < vec.size(); i++)
    {
        cout << i << ": " << vec[i] << endl;
    }
}

void Menu::addition()
{
    cout << "Az osszeadando szamok indexei: ";
    int x,y;
    cin >> x >> y;
    Complex n = vec[x].addition(vec[y]);
    vec.push_back(n);
    cout << "Az osszeadas eredmenye: " << n << endl;
}

void Menu::subtraction()
{
    cout << "A kivonando szamok indexei: ";
    int x,y;
    cin >> x >> y;
    Complex n = vec[x].subtraction(vec[y]);
    vec.push_back(n);
    cout << "A kivonas eredmenye: " << n << endl;
}

void Menu::multiplication()
{
    cout << "A szorzando szamok indexei: ";
    int x,y;
    cin >> x >> y;
    Complex n = vec[x].multiplication(vec[y]);
    vec.push_back(n);
    cout << "A szorzas eredmenye: " << n << endl;
}

void Menu::division()
{
    cout << "Az osztando szamok indexei: ";
    int x,y;
    cin >> x >> y;

    try
    {
        Complex n = vec[x].division(vec[y]);
        vec.push_back(n);
        cout << "Az osztas eredmenye: " << n << endl;
    }
    catch(Complex::ComplexError err)
    {
        cout << "Nullaval valo osztas nem megengedett!" << endl;
    }

}

void Menu::conjugation()
{
    cout << "Az kojugalando szam indexe: ";
    int x;
    cin >> x;
    Complex n = vec[x].conjugation();
    vec.push_back(n);
    cout << "Az konjugalas eredmenye: " << n << endl;
}
