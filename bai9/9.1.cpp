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
                return;
            else if (imaginary == 1)
                cout << "i";
            else if (imaginary == -1)
                cout << "- i";
            else if (imaginary < 0)
                cout << "- "<< imaginary << "i";
            else cout << imaginary << "i";
        }
        else 
        {
            cout << real << " ";
            if (imaginary == 0)
                return;
            else if (imaginary == 1)
                cout << "+ i";
            else if(imaginary == -1)
                cout<<"- i";
            else if (imaginary < 0)
                cout << "- " << -imaginary << "i";
            else
                cout << "+ " << imaginary << "i";
        }
    }
};

int main()
{
    Complex c1, c2;

    c1.input();
    c2.input();

    cout << "c1: ";
    c1.display();
    cout << endl;
    cout << "c2: ";
    c2.display();

    return 0;
}
