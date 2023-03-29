#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 1005; // 最大点数
vector<int> G[MAXN];   // 邻接表存图
bool vis[MAXN];        // 标记数组，记录每个点是否被访问过

int main()
{
    int n, m, s;
    cin >> n >> m >> s; // 输入点数、边数和起点
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;     // 输入一条边的两个端点
        G[u].push_back(v); // 存储这条边
        G[v].push_back(u); // 无向图需要存储两次
    }
    return 0;
}
