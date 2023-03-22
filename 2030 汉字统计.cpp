// Problem Description  统计给定文本文件中汉字的个数。

// Input  输入文件首先包含一个整数n，表示测试实例的个数，然后是n段文本。

// Output  对于每一段文本，输出其中的汉字的个数，每个测试实例的输出占一行。
// [Hint:]从汉字机内码的特点考虑~

// Sample Input
// 2
// WaHaHa! WaHaHa! 今年过节不说话要说只说普通话WaHaHa! WaHaHa!
// 马上就要期末考试了Are you ready?

// Sample Output
// 14
// 9
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar();
    while (n--)
    {
        string temp;
        getline(cin, temp);
        int cnt = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            // 汉字机内码首字符为1，表示负数，且占两个char大小
            if (temp[i] < 0)
            {
                i += 2;
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}