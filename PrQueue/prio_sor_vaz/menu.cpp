#include <iostream>
#include "menu.h"

using namespace std;


void Menu::run()
{
    cout << "=== Prioritasos sor ===" << endl;
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
            putIn();
            print();
            break;
        case 2:
            removeMax();
            print();
            break;
        case 3:
            getMax();
            print();
            break;
        case 4:
            checkEmpty();
            print();
            break;
        case 5:
            print();
            break;
        case 6:
            test();
            break;
        }
    }
    cout << "=== Viszontlatasra ===" << endl;
}


int Menu::selectMenu()
{
    cout << "Menu opciok:" << endl;
    cout << "0. Kilepes" << endl;
    cout << "1. Prior sorba berak" << endl;
    cout << "2. Legnagyobbat kivesz" << endl;
    cout << "3. Legnagyobbat lekerdez" << endl;
    cout << "4. Ures-e vizsgalat" << endl;
    cout << "5. Sort kiir" << endl;
    cout << "6. Stressz-teszt" << endl;
    cout << endl;

	cout << "Valasztott menupont: ";
	int m;
	cin >> m;
    while (m < 0 || m > 6)
	{
		cerr << "0 es 6 kozotti szam kell: ";
		cin >> m;
	}
	return m;
}


void Menu::putIn()
{
    cout << "Bekerulo elem: " << endl;
    Item e;
    cout << "Elem prioritasa (egesz): ";
    cin >> e.pr;
    cout << "Elembe kerulo adat (szoveg): ";
    cin >> e.data;
    pq.add(e);
}

void Menu::removeMax()
{
    try
    {
        Item e = pq.remMax();
        cout << "Kivett elem: " << e.data << endl;
        cout << "Prioritasa: " << e.pr << endl;
    }
    catch (PrQueue::Exception err)
    {
        if (err == PrQueue::EMPTY_PRQUEUE)
            cerr << "Ures a sor" << endl;
        else cerr << "Ismeretlen hiba";
    }
    //catch(...){}
}

void Menu::getMax()
{
    try
    {
        Item e = pq.getMax();
        cout << "Legnagyobb elem: " << e.data << endl;
        cout << "Prioritasa: " << e.pr << endl;
    }
    catch (PrQueue::Exception err)
    {
        if (err == PrQueue::EMPTY_PRQUEUE)
            cerr << "Ures a sor" << endl;
        else cerr << "Ismeretlen hiba";
    }
    //catch(...){}

}

void Menu::checkEmpty()
{
    if (pq.isEmpty())
        cout << "A sor ures." << endl;
    else
        cout << "A sor nem ures." << endl;
}

void Menu::print()
{
    PrQueue q(pq);
    cout << endl;
    cout << "Elemszam: " << q.size() << endl;
    cout << "Tartalom:" << endl;
    while (!q.isEmpty())
	{
	    Item elem = q.remMax();
        cout << "(" << elem.pr << ", " << elem.data << ")" << endl;
    }
    cout << endl;
}

void Menu::test()
{
    constexpr int n = 1000000;
	constexpr int p = 10000;
    PrQueue pq;
    cout << "Stressz-teszt " << n << " elemen." << endl;
    cout << "A sor pillanatnyi elemszama:" << endl;
    for (int i = 0; i < n; ++i)
	{
        if (i % p == 0)
			cout << i << endl;
        pq.add(Item(i, "a"));
    }
    cerr << "A sor vegso merete: " << pq.size() << endl;
    cerr << "A sor vegso kapacitasa: " << pq.capacity() << endl;
}
