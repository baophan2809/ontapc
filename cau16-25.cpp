#include <iostream>
using namespace std;
class Fraction
{
    int numerator;
    int denominator;

public:
    Fraction()
    {
        this->numerator = 0;
        this->denominator = 1;
    }
    Fraction(const Fraction &other)
    {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }
    static int timUocMax(int a, int b)
    {
        if (b == 0)
            return a;
        return timUocMax(b, a % b);
    }
    static void rutGon(int &tu, int &mau)
    {
        int uocChung = timUocMax(tu, mau);
        tu /= uocChung;
        mau /= uocChung;
    }
    friend ostream &operator<<(ostream &os, Fraction other)
    {
        rutGon(other.numerator, other.denominator);
        if (other.numerator == 0)
            os << 0 << endl;
        else if (other.numerator == other.denominator)
            os << 1 << endl;
        else if (other.denominator == 1)
            os << other.numerator << endl;
        else if (other.denominator == -1)
            os << -other.numerator << endl;
        else if (other.numerator * other.denominator < 0)
            os << "-" << abs(other.numerator) << "/" << abs(other.denominator) << endl;
        else
            os << abs(other.numerator) << "/" << abs(other.denominator) << endl;
        return os;
    }
    friend istream &operator>>(istream &is, Fraction &other)
    {
        is >> other.numerator;
        do
        {
            is >> other.denominator;
        } while (other.denominator == 0);
        return is;
    }
    Fraction operator+(const Fraction &other)
    {
        Fraction temp;
        temp.numerator = this->numerator * other.denominator + other.numerator * this->denominator;
        temp.denominator = this->denominator * other.denominator;
        return temp;
    }
    Fraction operator/(const Fraction &other)
    {
        Fraction temp;
        temp.numerator = this->numerator * other.denominator;
        temp.denominator = this->denominator * other.numerator;
        return temp;
    }
    friend bool operator==(const Fraction &f1, const Fraction &f2)
    {
        return (f1.numerator * f2.denominator == f2.numerator * f1.denominator);
    }
};
int main()
{
    Fraction f1;
    Fraction f2;
    cin >> f1 >> f2;
    cout << f1 << f2;
    cout << "f1 + f2 = " << f1 + f2;
    cout << "f1 / f2 = " << f1 / f2;
    if (f1 == f2)
        cout << "f1 = f2" << endl;
    else
        cout << "f1 != f2" << endl;
}