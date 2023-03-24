// Problem Description  有一只经过训练的蜜蜂只能爬向右侧相邻的蜂房，不能反向爬行。请编程计算蜜蜂从蜂房a爬到蜂房b的可能路线数。
// 其中，蜂房的结构如下所示。
// | 1 | 3 | 5 | 7 | ...
//   | 2 | 4 | 6 | 8 | ...
// 1下一步只能到2或3，2下一步只能到3或4...

// Input  输入数据的第一行是一个整数N,表示测试实例的个数，然后是N 行数据，每行包含两个整数a和b(0<a<b<50)。

// Output  对于每个测试实例，请输出蜜蜂从蜂房a爬到蜂房b的可能路线数，每个实例的输出占一行。

// Sample Input
// 2
// 1 2
// 3 6

// Sample Output
// 1
// 3

#include <iostream>

using namespace std;

int ways(int to)
{
    if (to == 2)
        return 1;
    if (to == 3)
        return 2;
    return ways(to - 1) + ways(to - 2);
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int from, to;
        cin >> from >> to;
        cout << ways(to - from + 1) << endl;
    }
    return 0;
}
