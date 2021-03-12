#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
#include <ostream>
class Complex
{
public:
    enum ComplexError{ZERO_DIVISION};

    Complex(double r, double i) : re(r),im(i){}

    Complex addition(const Complex s) const;
    Complex subtraction(const Complex s) const;
    Complex multiplication(const Complex s) const;
    Complex division(const Complex s) const;
    Complex conjugation() const;

    double getRe() const {return re;};
    double getIm() const {return im;};

    friend std::ostream& operator<< (std::ostream &os, const Complex &n);

private:
    double re;
    double im;
};

#endif // COMPLEX_H_INCLUDED
