#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Date
{
    int day, month, year;

public:
    Date()
    {
    }
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
};
class Student
{
    Date dt;
    string MSSV, name, address;

public:
    Student()
    {
    }
    Student(string MSSV, string name, string address, Date dt)
    {
        this->MSSV = MSSV;
        this->name = name;
        this->address = address;
        this->dt = dt;
    }
    void display()
    {
        cout << "- " << name << " (" << MSSV << ")" << endl;
    }
};

class Students
{
public:
    Students()
    {
        this->len = 0;
        pArr = nullptr;
    }
    Students(const Students &st)
    {
        this->len = st.len;
        this->pArr = new Student[len];
        for (int i = 0; i < len; i++)
            *(pArr + i) = *(st.pArr + i);
    }
    void display()
    {
        for (int i = 0; i < len; i++)
            pArr[i].display();
    }
    void push_back(const Student &other)
    {
        Student *temp = new Student[len + 1];
        for (int i = 0; i < len; i++)
            *(temp + i) = *(pArr + i);
        temp[len] = other;
        delete[] pArr;
        pArr = temp;
        len++;
    }
    void pop_back()
    {
        Student *temp = new Student[len - 1];
        for (int i = 0; i < len - 1; i++)
            *(temp + i) = *(pArr + i);
        delete[] pArr;
        pArr = temp;
        len--;
    }
    int size()
    {
        return len;
    }

private:
    int len;
    Student *pArr;
};

int main()
{
    Date dt1(12, 2, 2002);
    Student st1("26201242086", "Nguyen Hoc Lan", "12 Hoang Hoa Tham", dt1);

    Date dt2(12, 3, 2001);
    Student st2("26211441593", "Nguyen Quoc Nhat", "254 Nguyen Van Linh", dt2);

    Date dt3(8, 9, 2000);
    Student st3("26211238959", "Tran Thanh Thien", "128 Tai Do", dt3);

    Students sts1;
    sts1.push_back(st1); // sts1 contains: st1
    sts1.push_back(st2); // sts1 contains: st1, st2
    sts1.push_back(st3); // sts1 contains: st1, st2, st3

    Students sts2 = sts1; // sts2 contains: st1, st2, st3
    sts2.pop_back();      // sts2 contains: st1, st2
    sts2.pop_back();      // sts2 contains: st1
    sts2.push_back(st3);  // sts2 contains: st1, st3

    cout << "sts1 has " << sts1.size() << " students:" << endl;
    sts1.display();

    cout << "sts2 has " << sts2.size() << " students:" << endl;
    sts2.display();
    return 0;
}
