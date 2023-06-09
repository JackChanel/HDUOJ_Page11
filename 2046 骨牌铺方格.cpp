// Problem Description  在2×n的一个长方形方格中,用一个1× 2的骨牌铺满方格,输入n ,输出铺放方案的总数.
// 例如n=3时,为2× 3方格，骨牌的铺放方案有三种,如右图：
// _______________________________
// | ______  | ______  | ______  |
// | |    |  | |    |  | |    |  |
// |_|    |__|_|    |__|_|    |__|
// | |    |  | |    |  | |    |  |
// | |____|  | |____|  | |____|  |
// |_________|_________|_________|

// _______________________________
// | ______  | ________________  |
// | |    |  | |              |  |
// |_|    |__|_|______________|__|
// | |    |  | |              |  |
// | |____|  | |______________|  |
// |_________|_________|_________|

// _______________________________
// | ________________  | ______  |
// | |              |  | |    |  |
// |_|______________|__|_|    |__|
// | |              |  | |    |  |
// | |______________|  | |____|  |
// |___________________|_________|

// Input  输入数据由多行组成，每行包含一个整数n,表示该测试实例的长方形方格的规格是2×n (0<n<=50)。

// Output  对于每个测试实例，请输出铺放方案的总数，每个实例的输出占一行。

// Sample Input
// 1
// 3
// 2

// Sample Output
// 1
// 3
// 2

// Solve Description 分析后面每次加入一列发生的情况，发现也是斐波那契

#include <iostream>

using namespace std;

int dp[51] = {0, 1, 2, 3};
// 不采用递归，直接用数组缓存法(甚至可以简化为几个变量缓存)
void ways()
{
    for (int i = 4; i < 51; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
}

int main()
{
    ways();
    int n;
    while (cin >> n)
        cout << dp[n] << endl;
    return 0;
}