#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N]; // 邻接矩阵存储图
int dist[N]; // 存储当前点到生成树的最短距离
bool st[N];  // 存储当前点是否已加入生成树

int prim()
{
    memset(dist, 0x3f, sizeof(dist)); // 初始化点到生成树的距离为无穷大
    memset(st, false, sizeof(st));
    int res = 0;                // 存储最小生成树的权值之和
    for (int i = 0; i < n; i++) // 从第一个点开始
    {
        int t = -1;                  // 存储当前到生成树最小距离的点
        for (int j = 1; j <= n; j++) // 找到当前到生成树距离最小的点
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i && dist[t] == INF)
            return INF; // 如果当前点无法到达生成树，说明不连通，返回无穷大

        st[t] = true; // 将当前点加入生成树
        if (i)
            res += dist[t]; // 如果不是第一个点，将最小距离加入结果

        for (int j = 1; j <= n; j++) // 更新当前点到其他点的距离
            dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main()
{
    cin >> n >> m;

    memset(g, 0x3f, sizeof(g)); // 初始化为无穷大
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c); // 如果有重边，取距离最小的一条
    }

    int t = prim();
    if (t == INF)
        puts("impossible"); // 不连通
    else
        cout << t << endl;

    return 0;
}