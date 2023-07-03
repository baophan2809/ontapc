#include <iostream>

using namespace std;
class Fraction
{
private:
    int tuSo, mauSo;

public:
    Fraction()
    {
        tuSo = 0;
        mauSo = 1;
    }
    void input()
    {
        cin >> tuSo;
        do
        {
            cin >> mauSo;
        } while (mauSo == 0);
    }
    void display()
    {
        rutGonPhanSo();
        if (tuSo == 0)
            cout << 0 << endl;
        else if (tuSo == mauSo)
            cout << 1 << endl;
        else if (mauSo == 1)
            cout << tuSo << endl;
        else if (mauSo == -1)
            cout << mauSo << endl;
        else if (tuSo * mauSo < 0)
            cout << "-" << abs(tuSo) << "/" << abs(mauSo) << endl;
        else
            cout << abs(tuSo) << "/" << abs(mauSo) << endl;
    }
    int uocChungLonNhat(int a, int b)
    {
        if (b == 0)
            return a;
        else
            return uocChungLonNhat(b, a % b);
    }
    void rutGonPhanSo()
    {
        int uocChung = uocChungLonNhat(tuSo, mauSo);
        tuSo /= uocChung;
        mauSo /= uocChung;
    }
    Fraction sum(const Fraction &f2)
    {
        Fraction temp; // 5/7 + 1/2
        temp.tuSo = this->tuSo * f2.mauSo + f2.tuSo * this->mauSo;
        temp.mauSo = this->mauSo * f2.mauSo;
        return temp;
    }
    Fraction product(const Fraction &f2)
    {
        Fraction temp;
        temp.tuSo = tuSo * f2.tuSo;
        temp.mauSo = mauSo * f2.mauSo;
        return temp;
    }
    Fraction division(const Fraction &f2)
    {
        Fraction temp;
        temp.tuSo = tuSo * f2.mauSo;
        temp.mauSo = mauSo * f2.tuSo;
        return temp;
    }
};
int main()
{
    Fraction f1;
    f1.input();

    Fraction f2;
    f2.input();

    cout << "f1: ";
    f1.display();

    cout << "f2: ";
    f2.display();

    Fraction fSum = f1.sum(f2); // f1 khong bi thay doi gia tri
    cout << "f1 + f2: ";
    fSum.display();

    Fraction fProduct = f1.product(f2); // f1 khong bi thay doi gia tri
    cout << "f1 * f2: ";
    fProduct.display();

    Fraction fDivision = f1.division(f2); // f1 khong bi thay doi gia tri
    cout << "f1 / f2: ";
    fDivision.display();
    return 0;
}
