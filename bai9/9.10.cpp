#include <iostream>
#include <cmath>
using namespace std;

class Fraction
{
private:
    double numerator;
    double denominator;

public:
    Fraction()
    {
        numerator = 0;
        denominator = 1;
    }
    void rutGon()
    {
        int uocLonNhat = UCLN(numerator, denominator);
        numerator /= uocLonNhat;
        denominator /= uocLonNhat;
    }
    static int UCLN(int x, int y)
    {
        x = abs(x);
        y = abs(y);
        while (y != 0)
        {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }
    // tra ket qua sau khi cong (tien to)
    Fraction &operator++()
    {
        this->numerator += this->denominator;
        this->rutGon();
        return *this;
    }
    // tra ket qua truoc khi cong (hau to)
    Fraction operator++(int)
    {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }
    friend istream &operator>>(istream &is, Fraction &c);
    friend ostream &operator<<(ostream &os, const Fraction &c);
};
istream &operator>>(istream &is, Fraction &c)
{
    is >> c.numerator >> c.denominator;
    return is;
}

ostream &operator<<(ostream &os, const Fraction &c)
{
    if (c.numerator == 0)
        os << "0";
    else if (c.denominator == 1)
        os << c.numerator;
    else if (c.denominator == -1)
        os << -c.numerator;
    else if (c.numerator == c.denominator)
        os << "1";
    else if (c.numerator * c.denominator < 0)
        os << "-" << abs(c.numerator) << "/" << abs(c.denominator);
    else
        os << abs(c.numerator) << "/" << abs(c.denominator);
    return os;
}

int main()
{
    Fraction f;
    cin >> f;
    cout << "f: " << f << endl;
    cout << "++f: " << ++f << endl;
    cout << "f: " << f << endl;
    cout << "f++: " << f++ << endl;
    cout << "f: " << f;
    return 0;
}