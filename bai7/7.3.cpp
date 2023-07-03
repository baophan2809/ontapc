#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Student
{
private:
    char fullName[100];
    char id[100];
    char address[100];

public:
    void setDetail(string _id, string _fullName, string _address)
    {
        int a = _id.length();
        int b = _fullName.length();
        int c = _address.length();
        for (int i = 0; i < a; i++)
            id[i] = _id[i];
        id[a] = '\0';
        for (int i = 0; i < b; i++)
            fullName[i] = _fullName[i];
        fullName[b] = '\0';
        for (int i = 0; i < c; i++)
            address[i] = _address[i];
        address[c] = '\0';
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
    string getId()
    {
        return id;
    }
    string getFullName()
    {
        dinhDangThongTin(fullName);
        return fullName;
    }
    string getAddress()
    {
        dinhDangThongTin(address);
        return address;
    }
};
int main()
{
    Student st;
    string fullName;
    string id;
    string address;

    getline(cin, id);       // Student id
    getline(cin, fullName); // Student full name
    getline(cin, address);  // The address of the student

    st.setDetail(id, fullName, address);

    cout << "Student id: " << st.getId() << endl;
    cout << "Full name: " << st.getFullName() << endl;
    cout << "Address: " << st.getAddress() << endl;
    return 0;
}
