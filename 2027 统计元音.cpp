// Problem Description  统计每个元音字母在字符串中出现的次数。

// Input  输入数据首先包括一个整数n，表示测试实例的个数，然后是n行长度不超过100的字符串。

// Output  对于每个测试实例输出5行，格式如下：
// a:num1
// e:num2
// i:num3
// o:num4
// u:num5
// 多个测试实例之间由一个空行隔开。
// 请特别注意：最后一块输出后面没有空行：）

// Sample Input
// 2
// aeiou
// my name is ignatius

// Sample Output
// a:1
// e:1
// i:1
// o:1
// u:1
// a:2
// e:1
// i:3
// o:0
// u:1
#include <iostream>
#include <ctype.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar();
    while (n--)
    {
        int alphaSet[] = {0, 0, 0, 0, 0};
        string tag;
        getline(cin, tag);
        for (auto i : tag)
            switch (i)
            {
            case 'a':
                alphaSet[0]++;
                break;
            case 'e':
                alphaSet[1]++;
                break;
            case 'i':
                alphaSet[2]++;
                break;
            case 'o':
                alphaSet[3]++;
                break;
            case 'u':
                alphaSet[4]++;
                break;
            default:
                break;
            }
        char meta[] = "aeiou";
        for (int i = 0; i < 5; i++)
            cout << meta[i] << ":" << alphaSet[i] << endl;
    }
    return 0;
}