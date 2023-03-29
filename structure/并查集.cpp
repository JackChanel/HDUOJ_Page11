#include <iostream>
#include <set>
using namespace std;

const int MAX = 10010;
int p[MAX];

// 返回x所在的集合编号（即x所在的树根）
int find(int x)
{
    while (p[x] != x)
        x = p[x];
    return x;
}

// 带有路径压缩功能的集合查询
int findpro(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

// 将y所在集合合并到x所在集合
void merge(int x, int y)
{
    // p[find(x)] = find(y);
    p[findpro(x)] = findpro(y);
}

int main()
{
    int n, m; // n个结点(1~n)，m个关系
    cin >> n >> m;
    set<int> nodes;
    // 初始化：将每个节点都记为树根（自己的父节点指向自己）
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        nodes.insert(i);
    }

    // 构建关系集合
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        merge(x, y);
    }

    // 判断集合的个数
    int cnt = 0;
    set<int> root;
    for (auto i : nodes)
    {
        root.insert(find(i));
    }
    cout << root.size();
    return 0;
}

// 测试用例，输出应当为2，因为有两个集合。
// 5 5
// 1 2
// 1 3
// 2 3
// 4 5
// 5 4
