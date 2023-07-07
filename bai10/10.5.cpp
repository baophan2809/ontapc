#include <iostream>
#include <string>
using namespace std;
class fixInformation
{
    string fixName(string &name)
    {
        for (unsigned int i = 0; i < name.length(); i++)
        {
            if (i == 0 || name[i - 1] == ' ')
                name[i] = toupper(name[i]);
            else
                name[i] = tolower(name[i]);
        }
        return name;
    }
    bool setDate(int day, int month, int year)
    {
        if (year < 1 || month < 1 || month > 12 || day < 1)
            return false;

        int daymax[] = {31, 28 + ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (day > daymax[month - 1])
            return false;

        return true;
    }

public:
    friend class Employee;
};
class Employee
{
    int day, month, year;
    string name;
    long long salary;
    fixInformation fix;

public:
    Employee()
    {
        name = "Not Available";
        day = 1;
        month = 1;
        year = 2000;
        salary = 0;
    }
    void input()
    {
        do
        {
            getline(cin, name);
        } while (name.length() == 0);
        do
        {
            cin >> day >> month >> year;
        } while (fix.setDate(day, month, year) == false);
        cin >> salary;
    }
    void display()
    {
        cout << "- Full Name: " << fix.fixName(name) << endl;
        cout << "- Birth Date: " << day << "/" << month << "/" << year << endl;
        cout << "- Salary: " << salary << endl;
    }
    long long getSalary()
    {
        return salary;
    }
};
class Shop
{
    int count;
    string localBrand;
    Employee **pArr;

public:
    Shop()
    {
        count = 0;
    }
    void input()
    {
        getline(cin, localBrand);
        cin >> count;
        pArr = new Employee *[count];
        for (int i = 0; i < count; i++)
        {
            pArr[i] = new Employee();
            pArr[i]->input();
        }
    }
    void display()
    {
        if (count == 0)
        {
            cout << "\"" << localBrand << "\" "
                 << "has no employees" << endl;
        }
        else if (count == 1)
        {
            cout << "\"" << localBrand << "\" "
                 << "has an employee" << endl;
            pArr[0]->display();
        }
        else
        {
            cout << "\"" << localBrand << "\" "
                 << "has " << count << " employees" << endl;
            for (int i = 0; i < count; i++)
            {
                cout << "EMPLOYEE " << i + 1 << ":" << endl;
                pArr[i]->display();
            }
        }
    }
    long long getTotalSalary()
    {
        long long answer = 0;
        for (int i = 0; i < count; i++)
            answer += pArr[i]->getSalary();
        return answer;
    }
};
int main()
{
    Shop shop;
    shop.input();
    shop.display();
    cout << "Total salary: " << shop.getTotalSalary();
    return 0;
}
