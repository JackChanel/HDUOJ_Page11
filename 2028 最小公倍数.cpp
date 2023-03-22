// Problem Description  求n个数的最小公倍数。

// Input  输入包含多个测试实例，每个测试实例的开始是一个正整数n，然后是n个正整数。

// Output  为每组测试数据输出它们的最小公倍数，每个测试实例的输出占一行。你可以假设最后的输出是一个32位的整数。

// Sample Input
// 2 4 6
// 3 2 5 7

// Sample Output
// 12
// 70

// Solution
// 求解最小公倍数(Least Common Multiple) = a * b / 最大公约数(Greatest Common Divisor))，因此本题就是求解最大公约数后求最小公倍数。求解最大公约数可以用暴力解，从2开始到较小的那个数，或者使用辗转相除法求GCD！
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int GCD(int a, int b)
{
    int mins = min(a, b);
    int maxs = max(a, b);
    if (maxs % mins == 0)
        return mins;
    else
        return GCD(maxs % mins, mins);
}

int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}

int main()
{
    int n;
    while (cin >> n)
    {
        int res;
        cin >> res;
        for (int i = 1; i < n; i++)
        {
            int u;
            cin >> u;
            res = LCM(u, res);
        }
        cout << res << endl;
    }

    return 0;
}