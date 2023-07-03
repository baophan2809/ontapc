#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class Date
{
private:
    int day, month, year;

public:
    friend class Student;
    bool setDate()
    {
        if (year < 0 || month < 1 || month > 12)
            return false;
        int dayMax;
        switch (month)
        {
        case 4:
        case 6:
        case 9:
        case 11:
            dayMax = 30;
            break;
        case 2:
            if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
            {
                dayMax = 29;
                break;
            }
            dayMax = 28;
            break;
        default:
            dayMax = 31;
        }
        if (day < 1 || day > dayMax)
            return false;
        return true;
    }
} dt;
class Student
{
private:
    char fullName[200];
    char id[100];
    char address[100];
    char firstName[100];
    char lastName[100];

public:
    void tachHoTen(char name[])
    {
        int len = strlen(name);
        for (int i = 0; i < len; i++)
        {
            if (name[i] == ' ')
            {
                firstName[i] = '\0';
                break;
            }
            firstName[i] = fullName[i];
        }
        for (int i = len - 1; i >= 0; i--)
        {
            if (fullName[i] == ' ')
            {
                lastName[len - i - 1] = '\0';
                break;
            }
            lastName[len - i - 1] = fullName[i];
        }
        for (size_t i = 0; i < strlen(lastName) / 2; i++)
        {
            char temp = lastName[i];
            lastName[i] = lastName[strlen(lastName) - i - 1];
            lastName[strlen(lastName) - i - 1] = temp;
        }
    }
    void input()
    {
        cin.getline(id, 100);
        cin.getline(fullName, 200);
        dinhDangThongTin(fullName);
        do
        {
            cin >> dt.day >> dt.month >> dt.year;
        } while (dt.setDate() == false);
        cin.ignore();
        cin.getline(address, 100);
        dinhDangThongTin(address);
        tachHoTen(fullName);
    }
    void display()
    {
        cout << "Full name: " << fullName << endl;
        cout << "First name: " << firstName << endl;
        cout << "Last name: " << lastName << endl;
        cout << "Birth date: " << dt.day << "-" << dt.month << "-" << dt.year << endl;
        cout << "Address: " << address;
    }
    void xoaKiTu(char arr[], int index)
    {
        int n = strlen(arr);
        for (int i = index; i < n; i++)
            arr[i] = arr[i + 1];
        n--;
        arr[n] = '\0';
    }
    void dinhDangThongTin(char thongTin[])
    {
        while (thongTin[0] == ' ')
            xoaKiTu(thongTin, 0);
        if (thongTin[0] >= 'a' && thongTin[0] <= 'z')
            thongTin[0] = thongTin[0] - 32;
        for (size_t i = 1; i < strlen(thongTin); i++)
        {
            if (thongTin[i] == ' ')
            {
                while (thongTin[i + 1] == ' ')
                    xoaKiTu(thongTin, i + 1);
                if (thongTin[i + 1] >= 'a' && thongTin[i + 1] <= 'z')
                    thongTin[i + 1] = thongTin[i + 1] - 32;
                for (int h = i + 2; thongTin[h] != ' '; h++)
                {
                    if (thongTin[h] >= 'A' && thongTin[h] <= 'Z')
                        thongTin[h] = thongTin[h] + 32;
                }
            }
        }
    }
};
int main()
{
    Student st;
    st.input();
    st.display();
    return 0;
}
