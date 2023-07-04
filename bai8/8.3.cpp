#include <iostream>
#include <vector>

using namespace std;

class IntVector
{
public:
    IntVector()
    {
    }
    IntVector(int n, int value)
    {
        len = n;
        for (int i = 0; i < len; i++)
            *(pArr + i) = value;
    }
    ~IntVector()
    {
        delete[] pArr;
    }
    void display()
    {
        for (int i = 0; i < len; i++)
        {
            cout << pArr[i];
            if (i < len - 1)
                cout << " ";
        }
        cout << endl;
    }
    void push_back(int value)
    {
        pArr[len] = value;
        len ++;
    }

private:
    int len = 0;
    int *pArr = new int [0];
};

int main()
{
    IntVector vt1(4, 8);
    IntVector vt2;

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

    vt1.display();
    vt2.display();
    return 0;
}
