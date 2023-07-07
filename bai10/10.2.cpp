#include <iostream>
#include <string>
using namespace std;
class Manager
{
public:
    Manager()
    {
        this->basicSalary = 0;
        this->experience = 0;
    }
    void input()
    {
        getline(cin, name);
        cin >> basicSalary >> experience;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Salary: " << basicSalary + experience * basicSalary * 15 / 100 << endl;
        cout << "Experience: " << experience;
    }

private:
    string name;
    int basicSalary;
    int experience;
};
int main()
{
    Manager m;
    m.input();
    m.display();
    return 0;
}