#include <iostream>
typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535
using namespace std;
int visited[100];

// 构建顶点表
typedef struct
{
    VertexType vexs[MAXVEX];      // 顶点数组
    EdgeType arc[MAXVEX][MAXVEX]; // 边的矩阵表示
    int numVertexes, numEdges;    // 图中当前的顶点数和边数
} MGraph;

// 创建邻接矩阵
void CreatMgraph(MGraph *G)
{
    int i, j, k, w;
    cout << "输入顶点数和边数:" << endl;
    cin >> G->numVertexes >> G->numEdges;

    for (i = 0; i < G->numVertexes; i++)
    {
        cout << "请输入顶点名:" << endl;
        cin >> G->vexs[i];
    }
    // 初始化邻接矩阵
    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            G->arc[i][j] = INFINITY;
        }
    }
    // 构建邻接矩阵
    for (k = 0; k < G->numEdges; k++)
    {
        cout << "输入边（vi,vj）上的下标i,下标j和权w:" << endl;
        cin >> i >> j >> w;
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }
}

// 深度遍历算法
void DFS(MGraph G, int i)
{
    int j;
    visited[i] = true; // 标志位数组
    cout << G.vexs[i];
    for (j = 0; j < G.numVertexes; j++)
    {
        if (G.arc[i][j] == 1 && !visited[j])
        {
            DFS(G, j); // 递归算法
        }
    }
}

// 邻接矩阵的深度遍历
void DFSTraverse(MGraph G)
{
    int i;
    for (i = 0; i < G.numVertexes; i++)
    {
        visited[i] = false; // 初始化标志位数组
    }
    for (i = 0; i < G.numVertexes; i++)
    {
        if (!visited[i])
        {
            DFS(G, i);
        }
    }
}

int main()
{
    MGraph *grap = (MGraph *)malloc(sizeof(MGraph));
    CreatMgraph(grap);
    DFSTraverse(*grap);
    free(grap);
    return 0;
}
