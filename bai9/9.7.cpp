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
        this->len = 0;
        pStr = nullptr;
    }
    static int codeStrlen(const char *name)
    {
        int count = 0;
        while (*name++)
            count++;
        return count;
    }
    static void codeStrcpy(char *destination, const char *source)
    {
        while (*source)
            *destination++ = *source++;
        *destination = '\0';
    }
    void input()
    {
        char temp[100];
        cin >> temp;
        this->len = codeStrlen(temp);
        pStr = new char[len + 1];
        codeStrcpy(pStr, temp);
    }
    void display()
    {
        if (pStr != NULL)
            cout << pStr << endl;
    }
    MyString operator+(const MyString &other)
    {
        MyString temp;
        temp.len = this->len + other.len;
        temp.pStr = new char[temp.len + 1];
        codeStrcpy(temp.pStr, this->pStr);
        codeStrcpy(temp.pStr + this->len, other.pStr);
        return temp;
    }
    MyString operator+(const char *name)
    {
        MyString temp;
        temp.len = this->len + codeStrlen(name);
        temp.pStr = new char[temp.len + 1];
        codeStrcpy(temp.pStr, this->pStr);
        codeStrcpy(temp.pStr + this->len, name);
        return temp;
    }
    friend MyString operator+(const char *name, const MyString &other)
    {
        MyString temp;
        temp.len = codeStrlen(name) + other.len;
        temp.pStr = new char[temp.len + 1];
        codeStrcpy(temp.pStr, name);
        codeStrcpy(temp.pStr + codeStrlen(name), other.pStr);
        return temp;
    }
};

int main()
{
    MyString s1, s2;
    s1.input();
    s2.input();

    cout << "s1: ";
    s1.display();
    cout << "s2: ";
    s2.display();

    MyString s3 = s1 + s2;
    cout << "s3: ";
    s3.display();

    MyString s4 = "DTU" + s1;
    cout << "s4: ";
    s4.display();

    MyString s5 = s2 + "K25";
    cout << "s5: ";
    s5.display();

    return 0;
}
