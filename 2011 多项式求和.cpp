// Problem Description  多项式的描述如下：
// 1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + ...
// 现在请你求出该多项式的前n项的和。

// Input  输入数据由2行组成，首先是一个正整数m（m<100），表示测试实例的个数，第二行包含m个正整数，对于每一个整数(不妨设为n,n<1000），求该多项式的前n项的和。

// Output  对于每个测试实例n，要求输出多项式前n项的和。每个测试实例的输出占一行，结果保留2位小数。

// Sample Input
// 2
// 1 2

// Sample Output
// 1.00
// 0.50

#include <iostream>

using namespace std;

double result[1010];

void cal()
{
    result[1] = 1.0;
    for (int i = 2; i < 1004; i++)
    {
        result[i] = result[i - 1] + i % 2 == 0 ? -1.0 / i : 1.0 / i;
    }
}

int main()
{
    int n;
    cin >> n;
    cal();
    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u;
        printf("%.2lf\n", result[u]);
    }
    cout << endl;
    return 0;
}