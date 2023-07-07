#include <iostream>
#include <string>
using namespace std;
class Worker
{
public:
    Worker()
    {
        this->basicSalary = 0;
        this->level = 0;
    }
    void input()
    {
        getline(cin, name);
        cin >> basicSalary >> level;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Salary: " << basicSalary + level * basicSalary * 20 / 100 << endl;
        cout << "Level: " << level;
    }

private:
    string name;
    int basicSalary;
    int level;
};
int main()
{
    Worker w;
    w.input();
    w.display();
    return 0;
}