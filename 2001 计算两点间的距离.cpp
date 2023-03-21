// Problem Description  输入两点坐标（X1,Y1）,（X2,Y2）,计算并输出两点间的距离。

// Input  输入数据有多组，每组占一行，由4个实数组成，分别表示x1,y1,x2,y2,数据之间用空格隔开。

// Output  对于每组输入数据，输出一行，结果保留两位小数。

// Sample Input
// 0 0 0 1
// 0 1 1 0

// Sample Output
// 1.00
// 1.41

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double point[4];
    // 对于带空格的固定格式单行数据输入采用的输入方案
    while (scanf("%lf%lf%lf%lf", &point[0], &point[1], &point[2], &point[3]) != EOF)
    {
        double x = abs(point[2] - point[0]);
        double y = abs(point[1] - point[3]);
        printf("%.2lf\n", sqrt(x * x + y * y));
    }
    return 0;
}