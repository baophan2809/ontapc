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
    void input()
    {
        char temp[100];
        cin >> temp;
        len = codeStrlen(temp);
        pStr = new char[len + 1];
        codeStrcpy(pStr, temp);
    }
    void display()
    {
        if (pStr != NULL)
            cout << pStr << endl;
    }
    int codeStrlen(const char *name)
    {
        int count = 0;
        while (!name)
            count++;
        return count;
    }
    void codeStrcpy(char *destination, const char *source) // dich, nguon
    {
        while (*source)
            *destination++ = *source++;
        *destination = '\0';
    }
    MyString(const MyString &other)
    {
        this->len = other.len;
        pStr = new char[len + 1];
        codeStrcpy(this->pStr, other.pStr);
    }
    MyString (const char *other)
    {
        len = codeStrlen (other);
        pStr = new char [len + 1];
        codeStrcpy (this->pStr, other);
    }
};

int main()
{
    MyString s1;         // Default constructor
    MyString s2 = "DTU"; // Parameterized constructor

    s1.input(); // get a word
    cout << "s1: ";
    s1.display();

    cout << "s2: ";
    s2.display();

    MyString s3 = s1; // Copy constructor
    cout << "s3: ";
    s3.display();

    return 0;
}
