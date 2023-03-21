// Problem Description  输入一个百分制的成绩t，将其转换成对应的等级，具体转换规则如下：
// 90~100为A;
// 80~89为B;
// 70~79为C;
// 60~69为D;
// 0~59为E;

// Input  输入数据有多组，每组占一行，由一个整数组成。

// Output  对于每组输入数据，输出一行。如果输入数据不在0~100范围内，请输出一行：“Score is error!”。

// Sample Input
// 56
// 67
// 100
// 123

// Sample Output
// E
// D
// A
// Score is error!

#include <iostream>

using namespace std;

int main()
{
    int score;
    while (cin >> score)
    {
        char rank;
        if (score > 100)
            cout << "Score is error!" << endl;
        else
        {
            if (score >= 90 && score <= 100)
                rank = 'A';
            else if (score >= 80)
                rank = 'B';
            else if (score >= 70)
                rank = 'C';
            else if (score >= 60)
                rank = 'D';
            else if (score >= 0)
                rank = 'E';
            cout << rank << endl;
        }
    }
    return 0;
}