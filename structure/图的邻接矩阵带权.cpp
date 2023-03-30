#include <iostream>
#include <cstring>
#define MAXVEX 100
#define BLOCK -1
using namespace std;
bool visited[MAXVEX];

// 邻接矩阵图
struct MGraph
{
    int node[MAXVEX];         // 顶点数组
    int edge[MAXVEX][MAXVEX]; // 边的矩阵表示
    int nodes, edges;         // 图中当前的顶点数和边数
};
// 初始化访问位
void resetVisited()
{
    memset(visited, false, sizeof(visited));
}
// 初始化邻接矩阵
void resetGraph(MGraph &G)
{

    memset(G.edge, BLOCK, sizeof(G.edge));
}
// 创建邻接矩阵
void CreatMgraph(MGraph G)
{
    cout << "输入顶点数和边数:" << endl;
    cin >> G.nodes >> G.edges;
    for (int i = 0; i < G.nodes; i++)
    {
        cout << "请输入顶点名:" << endl;
        cin >> G.node[i];
    }
    resetGraph(G);

    // 构建邻接矩阵(无向图，双向绑定)
    for (int k = 0; k < G.edges; k++)
    {
        int i, j, w;
        cout << "输入边（i,j）和权w:" << endl;
        cin >> i >> j >> w;
        G.edge[i][j] = w;
        G.edge[j][i] = G.edge[i][j];
    }
}

// 深度遍历算法
void DFS(MGraph G, int node)
{
    visited[node] = true; // 访问位数组
    cout << G.node[node];
    for (int j = 0; j < G.nodes; j++)
    {
        if (G.edge[node][j] != BLOCK && !visited[j])
        {
            DFS(G, j); // 递归算法
        }
    }
}

// 邻接矩阵的深度遍历
void DFSTraverse(MGraph G)
{
    resetVisited();
    for (int node = 0; node < G.nodes; node++)
    {
        if (!visited[node])
        {
            DFS(G, node);
        }
    }
}

int main()
{
    MGraph *grap = (MGraph *)malloc(sizeof(MGraph));
    CreatMgraph(*grap);
    DFSTraverse(*grap);
    free(grap);
    return 0;
}
