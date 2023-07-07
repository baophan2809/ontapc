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
        this->pStr = nullptr;
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
        codeStrcpy(this->pStr, temp);
    }
    void display()
    {
        if (pStr != NULL)
            cout << pStr << endl;
    }
    char &operator[](const int &index)
    {

        return pStr[index];
    }
    MyString &operator=(const MyString &other)
    {
        this->len = other.len;
        pStr = new char[len + 1];
        codeStrcpy(this->pStr, other.pStr);
    }
    MyString &operator=(const char *name)
    {
        this->len = codeStrlen(name);
        pStr = new char[len + 1];
        codeStrcpy(pStr, name);
    }
};

int main()
{
    MyString s1;
    s1.input();

    MyString s2;
    s2 = s1;
    s2[0] = '_'; // ??? operator[](const int& index) {...}

    cout << "s1: ";
    s1.display();
    cout << "s2: ";
    s2.display();

    MyString s3;
    s3 = "Hello K25";
    cout << "s3: ";
    s3.display();

    return 0;
}
