#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imaginary;

public:
    Complex()
    {
        this->real = 0;
        this->imaginary = 0;
    }
    void input()
    {
        cin >> this->real >> this->imaginary;
    }
    void display()
    {
        if (real == 0)
        {
            if (imaginary == 0)
                cout << "0";
            else if (imaginary == 1)
                cout << "i";
            else if (imaginary == -1)
                cout << "- i";
            else if (imaginary < 0)
                cout << "- " << imaginary << "i";
            else
                cout << imaginary << "i";
            cout << endl;
        }
        else
        {
            cout << real << " ";
            if (imaginary == 0)
            {
                cout << endl;
                return;
            }
            else if (imaginary == 1)
                cout << "+ i";
            else if (imaginary == -1)
                cout << "- i";
            else if (imaginary < 0)
                cout << "- " << -imaginary << "i";
            else
                cout << "+ " << imaginary << "i";
            cout << endl;
        }
    }
    Complex operator-(const Complex &other)
    {
        Complex temp;
        temp.real = this->real - other.real;
        temp.imaginary = this->imaginary - other.imaginary;
        return temp;
    }
    Complex operator-(const double &other)
    {
        Complex temp;
        temp.real = this->real - other;
        temp.imaginary = this->imaginary;
        return temp;
    }
    friend Complex operator-(const double &number, const Complex &other)
    {
        Complex temp;
        temp.real = number - other.real;
        temp.imaginary = -other.imaginary;
        return temp;
    }
};

int main()
{
    Complex c1, c2;

    c1.input();
    c2.input();

    cout << "c1: ";
    c1.display();

    cout << "c2: ";
    c2.display();

    // -
    Complex diff;
    diff = c1 - c2;
    cout << "c1 - c2: ";
    diff.display();

    diff = c1 - 2;
    cout << "c1 - 2: ";
    diff.display();

    diff = 2 - c2;
    cout << "2 - c2: ";
    diff.display();

    return 0;
}
