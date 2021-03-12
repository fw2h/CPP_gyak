#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED


class Circle
{
private:
    Point c;
    double r;

public:
    Point getc() const { return c; };
    double getr() const { return r; };

    Circle(const Point &c, double r) : c(c), r(r) {}

    void setc(const Point &c);
    void setr(double r);

    bool contains(const Point &p) const;
};


#endif // CIRCLE_H_INCLUDED
