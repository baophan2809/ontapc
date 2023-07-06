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
    friend Fraction reduce(Fraction &other)
    {
        int uocChung = timUocMax(other.numerator, other.denominator);
        other.numerator /= uocChung;
        other.denominator /= uocChung;
        return other;
    }
    friend ostream &operator<<(ostream &os, Fraction other)
    {
        reduce(other);
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
    friend int operator==(const Fraction &f1, const Fraction &f2)
    {
        if (f1.numerator * f2.denominator == f2.numerator * f1.denominator)
            return 1;
        return -1;
    }
};
int main()
{
    Fraction f1;
    Fraction f2;
    cin >> f1 >> f2;
    cout << "f1: " << f1;
    cout << "f2: " << f2;
    Fraction f3 = f1;
    cout << "f3 = f1 = " << f3;
    Fraction f4 = f1 + f2;
    cout << "f1 + f2 = " << f4;
    Fraction f5 = f1 / f2;
    cout << "f1 / f2 = " << f5;
    int check = f1 == f2;
    if (check == 1)
        cout << "f1 = f2" << endl;
    else
        cout << "f1 != f2" << endl;
    Fraction f6;
    cout << "Enter f6 to test the reduce function: ";
    cin >> f6;
    cout << "Reduce f6: " << reduce(f6);
    return 0;
}