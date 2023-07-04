#include <iostream>
#include <vector>

using namespace std;

class IntVector
{
public:
    IntVector()
    {
        len = 0;
        pArr = nullptr;
    }
    IntVector(int n, int value)
    {
        len = n;
        pArr = new int[len];
        for (int i = 0; i < len; i++)
            *(pArr + i) = value;
    }
    IntVector(const IntVector &vt)
    {
        this->len = vt.len;
        pArr = new int[len];
        for (int i = 0; i < len; i++)
            *(pArr + i) = *(vt.pArr + i);
    }
    void display()
    {
        for (int i = 0; i < len; i++)
        {
            cout << *(pArr + i);
            if (i < len - 1)
                cout << " ";
        }
        cout << endl;
    }
    void push_back(int value)
    {
        int *temp = new int[len + 1];
        for (int i = 0; i < len; i++)
            *(temp + i) = *(pArr + i);
        temp[len] = value;
        delete[] pArr;
        pArr = temp;
        len++;
    }
    void pop_back()
    {
        int *temp = new int[len - 1];
        for (int i = 0; i < len; i++)
            *(temp + i) = *(pArr + i);
        delete[] pArr;
        pArr = temp;
        len--;
    }
    ~IntVector()
    {
    }

private:
    int len;
    int *pArr;
};
int main()
{
    IntVector vt1(4, 8); // 8 8 8 8

    IntVector vt2 = vt1; // 8 8 8 8
    vt2.pop_back();      // 8 8 8
    vt2.pop_back();      // 8 8

    // Number of new items
    int newItems;
    cin >> newItems;

    // Add items
    for (int i = 0; i < newItems; i++)
    {
        int val;
        cin >> val;
        vt2.push_back(val);
    }

    vt1.display(); // 8 8 8 8
    vt2.display(); // ???
    return 0;
}
