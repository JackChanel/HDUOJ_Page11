// 6 10
// 1 2 1
// 1 3 3
// 1 6 5
// 2 4 3
// 2 6 6
// 3 5 7
// 3 6 4
// 4 5 2
// 4 6 5
// 5 6 1

#include <iostream>
#include <cstring>
using namespace std;

const int INF = 0xffff; // 定义正无穷

int nodeSize;          // 图中节点个数
int graph[1010][1010]; // 邻接矩阵存储图

int prim()
{
    int dis[1010];                   // 存储当前节点到已选定节点集合的最小距离
    bool vis[1010];                  // 标记当前节点是否已加入已选定节点集合
    memset(vis, false, sizeof(vis)); // 初始化vis数组
    memset(dis, INF, sizeof(dis));   // 初始化dis数组
    dis[1] = 0;                      // 选定1号节点为起点
    int ans = 0;                     // 存储最小生成树的权值和
    for (int i = 1; i <= nodeSize; i++)
    {
        int u = 0;
        for (int j = 1; j <= nodeSize; j++)
            if (!vis[j] && (u == 0 || dis[j] < dis[u]))
                u = j;

        vis[u] = true;
        ans += dis[u];

        for (int v = 1; v <= nodeSize; v++)
            if (!vis[v] && graph[u][v] < dis[v])
                dis[v] = graph[u][v];
    }
    return ans;
}

int main()
{
    cin >> nodeSize;
    memset(graph, INF, sizeof(graph));
    int edgeSize;
    cin >> edgeSize;
    while (edgeSize--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a][b] = graph[b][a] = w;
    }
    cout << prim() << endl; // 输出最小生成树的权值和
    return 0;
}
