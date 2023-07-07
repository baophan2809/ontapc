#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
private:
    int len;
    char *pStr;

public:
    MyString()
    {
        pStr = nullptr;
        len = 0;
    }
    int length()
    {
        return len;
    }
    static int codeStrlen(const char *name)
    {
        int dem = 0;
        while (*name++)
            dem++;
        return dem;
    }
    static void codeStrcpy(char *destination, const char *source)
    {
        while (*source)
            *destination++ = *source++;
        *destination = '\0';
    }
    void display()
    {
        if (pStr != NULL)
            cout << pStr << endl;
    }
    friend istream &operator>>(istream &is, MyString &other)
    {
        char temp[100];
        is >> temp;
        other.len = codeStrlen(temp);
        other.pStr = new char[other.len + 1];
        codeStrcpy(other.pStr, temp);
        return is;
    }
    friend ostream &operator<<(ostream &os, const MyString &other)
    {
        if (other.pStr != NULL)
            os << other.pStr;
        return os;
    }
    friend istream &getline(istream &is, MyString &other)
    {
        char temp[100];
        is.getline(temp, 100);
        other.len = codeStrlen(temp);
        other.pStr = new char[other.len + 1];
        codeStrcpy(other.pStr, temp);
        return is;
    }
};

int main()
{
    MyString s1, s2;

    cin >> s1;

    do
    {
        getline(cin, s2);
    } while (s2.length() == 0);

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2;

    return 0;
}
