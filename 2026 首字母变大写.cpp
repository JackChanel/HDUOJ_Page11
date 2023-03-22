// Problem Description  输入一个英文句子，将每个单词的第一个字母改成大写字母。

// Input  输入数据包含多个测试实例，每个测试实例是一个长度不超过100的英文句子，占一行。

// Output  请输出按照要求改写后的英文句子。

// Sample Input
// i like acm
// i want to get an accepted

// Sample Output
// I Like Acm
// I Want To Get An Accepted

#include <iostream>
#include <ctype.h>

using namespace std;

int main()
{
    string tag;
    while (getline(cin, tag))
    {
        cout << (char)toupper(tag[0]);
        for (int i = 1; i < tag.size(); i++)
        {
            if (tag[i - 1] == ' ')
                cout << (char)toupper(tag[i]);
            else
                cout << tag[i];
        }
        cout << endl;
    }

    return 0;
}