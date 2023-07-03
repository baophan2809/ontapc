#include <iostream>
using namespace std;
class Date
{
private:
    int day, month, year;

public:
    void input()
    {
        do
        {
            cin >> day >> month >> year;
        } while (checkDate() == false && cout << "Invalid date\n");
    }
    void display()
    {
        cout << day << "-" << month << "-" << year << endl;
    }
    int dayOfTheYear()
    {
        int countDay = day;
        for (int i = 1; i < month; i++)
            countDay += getDayMax(i);
        return countDay;
    }
    int getDayMax(int month)
    {
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
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                dayMax = 29;
            else
                dayMax = 28;
            break;
        default:
            dayMax = 31;
        }
        return dayMax;
    }
    bool checkDate()
    {
        if (year < 0)
            return false;
        if (month < 1 || month > 12)
            return false;
        int dayMax = getDayMax(month);
        if (day > dayMax || day < 1)
            return false;
        return true;
    }
};
int main()
{
    Date dt;
    dt.input();
    dt.display();
    cout << dt.dayOfTheYear();
    return 0;
}
