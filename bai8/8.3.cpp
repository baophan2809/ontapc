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
        pArr = new int[len];
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
        int *temp = new int[len + 1];
        for (int i = 0; i < len; i++)
            *(temp + i) = *(pArr + i);
        temp[len] = value;
        delete [] pArr;
        pArr = temp;
        len++;
    }

private:
    int len;
    int *pArr = nullptr;
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
