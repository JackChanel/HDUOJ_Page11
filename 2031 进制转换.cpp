// Problem Description  输入一个十进制数N，将它转换成R进制数输出。

// Input  输入数据包含多个测试实例，每个测试实例包含两个整数N(32位整数)和R（2<=R<=16, R<>10）。

// Output  为每个测试实例输出转换后的数，每个输出占一行。如果R大于10，则对应的数字规则参考16进制（比如，10用A表示，等等）。

// Sample Input
// 7 2
// 23 12
// -4 3

// Sample Output
// 111
// 1B
// -11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char meta[] = {'F', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E'};
int main()
{
    int num, radix;
    while (scanf("%d%d", &num, &radix) != EOF)
    {
        int negitiveFlag = num < 0 ? true : false;
        num = abs(num);
        vector<char> result_rev;
        while (num)
        {
            result_rev.push_back(meta[num % radix]);
            num /= radix;
        }
        if (negitiveFlag)
            cout << "-";
        reverse(result_rev.begin(), result_rev.end());
        for (auto i : result_rev)
            cout << i;
        cout << endl;
    }

    return 0;
}