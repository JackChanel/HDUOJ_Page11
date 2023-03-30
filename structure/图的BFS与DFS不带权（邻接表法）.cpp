#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

const int MAX = 1010; // 图的最多个数
vector<int> G[MAX];
bool visited[MAX];

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        if (!visited[node])
        {
            cout << node;
            visited[node] = true;
            for (auto i : G[node])
                q.push(i);
        }
    }
}

void dfs(int node)
{
    stack<int> st;
    st.push(node);
    while (!st.empty())
    {
        node = st.top();
        st.pop();
        if (!visited[node])
        {
            cout << node;
            visited[node] = true;
            for (auto i : G[node])
                st.push(i);
        }
    }
}

void initVisited()
{
    memset(visited, false, sizeof(visited));
}
int main()
{
    int nodes, edges, firstNode; // 点个数，边个数，第一个点
    cin >> nodes >> edges >> firstNode;
    for (int i = 0; i < edges; i++) // 存边信息
    {
        int nodex, nodey; // 边的两个端点
        cin >> nodex >> nodey;
        // 因为是无向图，需要存双向关系
        G[nodex].push_back(nodey);
        G[nodey].push_back(nodex);
    }
    initVisited();
    dfs(firstNode);
    initVisited();
    bfs(firstNode);
    return 0;
}

// 7 10 1
// 1 2
// 1 4
// 2 3
// 2 5
// 2 6
// 3 4
// 4 6
// 5 6
// 5 7
// 6 7

// 5 4 1
// 1 2
// 1 3
// 3 5
// 4 5