#include "complex.h"


using namespace std;

Complex Complex::addition(const Complex s) const
{
    Complex n(re + s.getRe(), s.getIm() + im);
    return n;
}

Complex Complex::subtraction(const Complex s) const
{
    Complex n(re - s.getRe(), im - s.getIm());
    return n;
}

Complex Complex::multiplication(const Complex s) const
{
    Complex n(re * s.getRe() - im * s.getIm(), re * s.getIm() + s.getRe() * im);
    return n;
}

Complex Complex::division(const Complex s) const
{
    double d1 = (s.getRe() * s.getRe() + s.getIm() * s.getIm());
    double d2 = (s.getRe() * s.getRe() + s.getIm() * s.getIm());
    if (d1 == 0 || d2 == 0) throw ZERO_DIVISION;
    double n1 = (re * s.getRe() + im * s.getIm())/d1;
    double n2 = (s.getRe() * im - re * s.getIm())/d2;
    Complex n(n1,n2);
    return n;
}

Complex Complex::conjugation() const
{
    Complex n(re, im * (-1));
    return n;
}

std::ostream& operator<< (std::ostream &os, const Complex &n)
{
    if (n.im >= 0)
    {
        os << n.re << '+' << n.im << "*i";
    }
    else
    {
        os << n.re << n.im << "*i";
    }

    return os;
}
