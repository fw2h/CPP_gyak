#include <iostream>
#include <fstream>

using namespace std;

struct Kaktusz
{
//private:
    string nev;
    string os;
    string szin;
    unsigned int meret;
//public:
    //friend istream& operator>>(istream& in, Kaktusz& k);
    //friend ostream& operator<<(ostream& out, const Kaktusz& k);
};


istream& operator>>(istream& in, Kaktusz& k)
{
    return in >> k.nev >> k.os >> k.szin >> k.meret;
}

ostream& operator<<(ostream& out, const Kaktusz& k)
{
    return out << k.nev << k.os << k.szin << k.meret;
}

enum Status
{
    norm,
    abnorm
};

void read(Status &st, Kaktusz &k, istream &in)
{
    in >> k;
    st = in.fail() ? abnorm : norm;
}

int select(const string& in_name, const string& out1_name, const string& out2_name)
{
	ifstream in(in_name);
	if (in.fail())
	{
		cerr << "Hiba az input fajl megnyitasakor." << endl;
		return 1;
	}
    ofstream out1(out1_name);
	if (out1.fail())
    {
		cerr << "Hiba az elso output fajl megnyitasakor." << endl;
		return 2;
	}
    ofstream out2(out2_name);
	if (out2.fail())
    {
		cerr << "Hiba a masodik output fajl megnyitasakor." << endl;
		return 3;
	}

    Kaktusz k;
    Status st;
    read(st, k, in);
    while(st == norm)
    {
        if(k.szin == "piros")
            out1 << k.nev << endl;
        if(k.os == "mexico")
            out2 << k.nev << endl;
        read(st, k ,in);
    }

	return 0;
}

#define NORMAL_MODE1
#ifdef NORMAL_MODE

int main()
{
    return select("inp.txt", "out_piros.txt", "out_mexikoi.txt");
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

unsigned int countLines(const char* name)
{
    // SZAMLALAS (c ~ db, t:enor ~ file:infile(S))
	ifstream file(name);
	unsigned int db = 0;
    string line;
    while (getline(file, line))
		++db;
	return db;
}

TEST_CASE("URES s", "")
{
    select("inp0.txt", "out0_piros.txt", "out0_mexikoi.txt");
    CHECK(0 == countLines("out0_piros.txt");
    CHECK(0 == countLines("out0_mexikoi.txt");
}


TEST_CASE("Egyelem s", "")
{
    select("inp1.txt", "out1_piros.txt", "out1_mexikoi.txt");
    CHECK(1 == countLines("out1_piros.txt");
    CHECK(1 == countLines("out1_mexikoi.txt");
}
#endif
