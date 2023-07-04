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
    Fraction(int num, int den)
    {
        tuSo = num;
        mauSo = den;
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
            cout << -tuSo << endl;
        else if (tuSo * mauSo < 0)
            cout << "-" << abs(tuSo) << "/" << abs(mauSo) << endl;
        else
            cout << abs(tuSo) << "/" << abs(mauSo) << endl;
    }
    void rutGonPhanSo()
    {
        int uocChung = uocChungLonNhat(tuSo, mauSo);
        tuSo /= uocChung;
        mauSo /= uocChung;
    }
    int uocChungLonNhat(int a, int b)
    {
        if (b == 0)
        return a;
        return uocChungLonNhat(b, a % b);
    }
};
int main()
{
    int num, den;
    cin >> num >> den;

    Fraction *pF = new Fraction(num, den);
    Fraction f;

    pF->display(); // Fraction from 'num' and 'den'
    f.display();   // 0

    return 0;
}
