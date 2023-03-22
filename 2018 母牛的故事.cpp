// Problem Description  有一头母牛，它每年年初生一头小母牛。每头小母牛从第四个年头开始，每年年初也生一头小母牛。请编程实现在第n年的时候，共有多少头母牛？

// Input  输入数据由多个测试实例组成，每个测试实例占一行，包括一个整数n(0<n<55)，n的含义如题目中描述。
// n=0表示输入数据的结束，不做处理。

// Output  对于每个测试实例，输出在第n年的时候母牛的数量。
// 每个输出占一行。

// Sample Input
// 2
// 4
// 5
// 0

// Sample Output
// 2
// 4
// 6

#include <iostream>

using namespace std;

// 递归法，时间复杂度高，因为很多help是重复计算，采用数组缓存结果可以提高效率
int help(int year)
{
  if (year < 4)
    return year;
  return help(year - 1) + help(year - 3);
}

int main()
{
  int year;
  while (cin >> year, year)
  {
    cout << help(year) << endl;
  }
  return 0;
}

// 以下是数组缓存的算法
// int main()
// {
//   int n, i;
//   int fab[55] = {1, 2, 3, 4, 6};

//   for (i = 5; i < 55; i++)
//     fab[i] = fab[i - 1] + fab[i - 3];

//   while (scanf("%d", &n), n)
//   {
//     printf("%d\n", fab[n - 1]);
//   }

//   return 0;
// }
