// Problem Description  给定三条边，请你判断一下能不能组成一个三角形。

// Input  输入数据第一行包含一个数M，接下有M行，每行一个实例，包含三个正数A,B,C。其中A,B,C <1000;

// Output  对于每个测试实例，如果三条边长A,B,C能组成三角形的话，输出YES，否则NO。

// Sample Input
// 2
// 1 2 3
// 2 2 2

// Sample Output
// NO
// YES

#include <iostream>
using namespace std;

int main(void)
{
    int A, B, C, M;
    cin >> M;
    while (M--)
    {
        cin >> A >> B >> C;
        if (A + B > C && A + C > B && B + C > A)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
