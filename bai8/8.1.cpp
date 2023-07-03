#include <iostream>
using namespace std;

class Date
{
private:
    int day, month, year;

public:
    Date()
    {
        day = 1;
        month = 1;
        year = 1900;
    }
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void display()
    {
        cout << day << "-" << month << "-" << year << endl;
    }
    void input()
    {
        cin >> day >> month >> year;
    }
    int differentDays(Date &dt4)
    {
        int count1 = this->countDay(day, month, year);
        int count2 = dt4.countDay(dt4.day, dt4.month, dt4.year);
        int answer = abs(count1 - count2);
        return answer;
    }
    int dayOfTheYear(int _day, int _month, int _year)
    {
        int dayOfYear = _day;
        for (int i = 0; i < _month; i++)
        {
            switch (i)
            {
                {
                case 4:
                case 6:
                case 9:
                case 11:
                    dayOfYear += 30;
                    break;
                case 2:
                    if (_year % 400 == 0 || (_year % 100 != 0 && _year % 4 == 0))
                    {
                        dayOfYear += 29;
                        break;
                    }
                    dayOfYear += 28;
                    break;
                default:
                    dayOfYear += 31;
                }
            }
        }
        return dayOfYear;
    }
    int countDay(int _day, int _month, int _year)
    {
        int count = dayOfTheYear(_day, _month, _year);
        for (int i = 0; i < _year; i++)
        {
            if (i % 400 == 0 || (i % 100 != 0 && i % 4 == 0))
                count += 366;
            else
                count += 365;
        }
        return count;
    }
};
int main()
{
    Date dt1;
    Date dt2(20, 10, 2001);
    Date dt3;
    Date dt4;

    dt3.input();
    dt4.input();

    dt1.display(); // 1-1-1900
    dt2.display(); // 20-10-2001
    dt3.display();
    dt4.display();

    cout << dt3.differentDays(dt4);

    return 0;
}
