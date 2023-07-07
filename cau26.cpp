#include <iostream>
#include <string>
using namespace std;
class Person
{
private:
    string name;
    int yob; // year of birth

public:
    virtual void input()
    {
        cin.ignore();
        getline(cin, name);
        cin >> yob;
    }

    virtual void display()
    {
        cout << "Name: " << name << endl;
        cout << "Year of birth: " << yob << endl;
    }

    virtual int getYob()
    {
        return yob;
    }

    virtual long getSalary() = 0;
};

class Employee : public Person
{
private:
    float sc; // salary coeff

public:
    void input()
    {
        Person::input();
        cin >> sc;
    }

    void display()
    {
        Person::display();
        cout << "Salary coefficient: " << sc << endl;
        cout << "Salary: " << getSalary() << endl;
    }

    long getSalary()
    {
        return sc * 1500000;
    }
    int getSc()
    {
        return sc;
    }
    void setSc (float value)
    {
        this->sc = value;
    }
};

class FootballPlayer : public Person
{
private:
    int nogs; // number of goals scored

public:
    void input()
    {
        Person::input();
        cin >> nogs;
    }

    void display()
    {
        Person::display();
        cout << "Number of goals scored: " << nogs << endl;
        cout << "Salary: " << getSalary() << endl;
    }

    long getSalary()
    {
        return 10000000 + nogs * 350000;
    }
};
class Group
{
    int n;
    Person **a;
public:
    void input()
    {
        cin >> n;
        a = new Person *[n];
        for (int i = 0; i < n; i++)
        {
            int type;
            cout << "Type of person you want to add: " << endl;
            cout << "1. Employee" << endl;
            cout << "2. FootballPlayer" << endl;
            cin >> type;
            if (type == 1)
            {
                a[i] = new Employee ();
                a[i]->input();
            }
            else
            {
                a[i] = new FootballPlayer ();
                a[i]->input();
            }
        }
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << ": " << endl;
            a[i]->display();
        }
    }
    void sort()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i]->getSalary() > a[j]->getSalary())
                {
                    swap(a[i], a[j]);
                }
            }
        }
    }
    void increase()
    {
        for (int i = 0; i < n; i++)
        {
            Employee *temp = dynamic_cast<Employee*>(a[i]);
            if (temp != nullptr && temp->getYob() < 1970)
                temp->setSc(temp->getSc() * 1.33);
        }
    }

};

int main()
{
    Group group;
    group.input();
    group.display(); // check before sort
    group.sort();
    group.display(); // check after sort
    group.increase();
    group.sort();
    group.display();
}
