#include <iostream>
using namespace std;
class Date
{
private:
    int day, month, year;

public:
    bool setDate(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
        if (checkDate())
            return true;
        return false;
    }
    int getDay()
    {
        return this->day;
    }
    int getMonth()
    {
        return this->month;
    }
    int getYear()
    {
        return this->year;
    }
    bool checkDate()
    {
        if (year < 0)
            return false;
        if (month < 1 || month > 12)
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
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                dayMax = 29;
            else
                dayMax = 28;
            break;
        default:
            dayMax = 31;
        }
        if (day > dayMax || day < 1)
            return false;
        return true;
    }
};
int main()
{
    Date dt;
    int day, month, year;
    cin >> day >> month >> year;
    if (dt.setDate(day, month, year))
    {
        cout << dt.getDay() << "-" << dt.getMonth() << "-" << dt.getYear();
    }
    else
    {
        cout << "Invalid date";
    }
    return 0;
}
