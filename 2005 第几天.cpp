// Problem Description  给定一个日期，输出这个日期是该年的第几天。

// Input  输入数据有多组，每组占一行，数据格式为YYYY/MM/DD组成，具体参见sample input ,另外，可以向你确保所有的输入数据是合法的。

// Output  对于每组输入数据，输出一行，表示该日期是该年的第几天。

// Sample Input
// 1985/1/20
// 2006/3/12

// Sample Output
// 20
// 71

#include <iostream>

using namespace std;
const int monthDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int runDay[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isRun(int year)
{
    bool run = false;
    if (year % 4 == 0 && year % 100 != 0)
        run = true;
    if (year % 400 == 0)
        run = true;
    return run;
}

int main()
{
    int year, month, day;
    while (scanf("%d/%d/%d", &year, &month, &day) != EOF)
    {
        int result = 0;
        if (isRun(year))
        {
            for (int i = 0; i < month - 1; i++)
            {
                result += runDay[i];
            }
        }
        else
        {
            for (int i = 0; i < month - 1; i++)
            {
                result += monthDay[i];
            }
        }
        result += day;
        cout << result << endl;
    }

    return 0;
}