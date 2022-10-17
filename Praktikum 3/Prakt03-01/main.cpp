#include <iostream>
using namespace std;
int main()
{
    int year1, year2, month1, month2, day1, day2;
    cout << "Please enter day, month and year of the first date sequentially.\n";
    cin >> day1 >> month1 >> year1;
    cout << "Please enter day, month and year of the second date sequentially.\n";
    cin >> day2 >> month2 >> year2;
    if (year1 > year2)
    {
        cout << "The second date comes first\n";
    }
    else if (year2 > year1)
    {
        cout << "The first date comes first\n";
    }
    else if (month1 > month2)
    {
        cout << "The second date comes first\n";
    }
    else if (month2 > month1)
    {
        cout << "The first date comes first\n";
    }
    else if (day1 > day2)
    {
        cout << "The second date comes first\n";
    }
    else if (day2 > day1)
    {
        cout << "The first date comes first\n";
    }
    else
    {
        cout << "The dates are the same\n";
    }
    system("PAUSE");
    return 0;
}
