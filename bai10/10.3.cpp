#include <iostream>
#include <string>
using namespace std;
class Employee
{
protected:
    string name;
    double basicSalary;

public:
    virtual void input() = 0;
    virtual void display() = 0;
    virtual double getSalary() = 0;
};
class Worker : public Employee
{
private:
    int level;

public:
    Worker()
    {
        this->basicSalary = 0;
        this->level = 0;
    }
    void input()
    {
        do
        {
            getline(cin, name);
        } while (name.length() == 0);
        cin >> basicSalary;
        cin >> level;
    }
    void display()
    {
        cout << " - Name: " << name << endl;
        cout << " - Basic Salary: " << basicSalary << endl;
        cout << " - Salary: " << getSalary() << endl;
        cout << " - Level: " << level << endl;
    }
    double getSalary()
    {
        return basicSalary * (1 + level * 0.2);
    }
};
class Manager : public Employee
{
private:
    int experience;

public:
    Manager()
    {
        this->basicSalary = 0;
        this->experience = 0;
    }
    void input()
    {
        do
        {
            getline(cin, name);
        } while (name.length() == 0);
        cin >> basicSalary;
        cin >> experience;
    }
    void display()
    {
        cout << " - Name: " << name << endl;
        cout << " - Basic Salary: " << basicSalary << endl;
        cout << " - Salary: " << getSalary() << endl;
        cout << " - Experience: " << experience << endl;
    }
    double getSalary()
    {
        return basicSalary * (1 + experience * 0.15);
    }
};
class EmployeeSystem
{
    int count;
    Employee **pArr;

public:
    EmployeeSystem()
    {
        this->count = 0;
        this->pArr = nullptr;
    }
    void input()
    {
        cin >> count;
        pArr = new Employee *[count];
        for (int i = 0; i < count; i++)
        {
            int type;
            cin >> type;
            if (type == 1)
                pArr[i] = new Worker();
            else
                pArr[i] = new Manager();
            pArr[i]->input();
        }
    }
    void display()
    {
        sort();
        for (int i = 0; i < count; i++)
        {
            cout << "Employee [" << i + 1 << "]:" << endl;
            pArr[i]->display();
        }
    }
    void sort()
    {
        for (int i = 0; i < count; i++)
            for (int k = i + 1; k < count; k++)
            {
                if (pArr[i]->getSalary() > pArr[k]->getSalary())
                    swap(pArr[i], pArr[k]);
            }
    }
};
int main()
{
    EmployeeSystem es;
    es.input();
    es.display();
    return 0;
}
