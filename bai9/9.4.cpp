#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imaginary;

public:
    friend istream &operator>>(istream &is, Complex &other)
    {
        is >> other.real >> other.imaginary;
        return is;
    }
    friend ostream &operator<<(ostream &os, const Complex &other)
    {
        if (other.real == 0)
        {
            if (other.imaginary == 0)
                os << "0";
            else if (other.imaginary == 1)
                os << "i";
            else if (other.imaginary == -1)
                os << "- i";
            else if (other.imaginary < 0)
                os << "- " << other.imaginary << "i";
            else
                os << other.imaginary << "i";
        }
        else
        {
            os << other.real << " ";
            if (other.imaginary == 0)
            {
            }
            else if (other.imaginary == 1)
                os << "+ i";
            else if (other.imaginary == -1)
                os << "- i";
            else if (other.imaginary < 0)
                os << "- " << -other.imaginary << "i";
            else
                os << "+ " << other.imaginary << "i";
        }
        return os;
    }
};

int main()
{
    Complex c1, c2;

    cin >> c1 >> c2;

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    return 0;
}
