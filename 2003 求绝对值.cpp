// Problem Description  求实数的绝对值。

// Input  输入数据有多组，每组占一行，每行包含一个实数。

// Output  对于每组输入数据，输出它的绝对值，要求每组数据输出一行，结果保留两位小数。

// Sample Input
// 123
// -234.00

// Sample Output
// 123.00
// 234.00

#include <iostream>

using namespace std;

int main()
{
    double number;
    while (cin >> number)
    {
        printf("%.2lf\n", abs(number));
    }
    return 0;
}