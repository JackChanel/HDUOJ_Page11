// Problem Description  对于表达式n^2+n+41，当n在（x,y）范围内取整数值时（包括x,y）(-39<=x<y<=50)，判定该表达式的值是否都为素数。

// Input  输入数据有多组，每组占一行，由两个整数x，y组成，当x=0,y=0时，表示输入结束，该行不做处理。

// Output  对于每个给定范围内的取值，如果表达式的值都为素数，则输出"OK",否则请输出“Sorry”,每组输出占一行。

// Sample Input
// 0 1
// 0 0

// Sample Output
// OK

#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<int, bool> map;

bool isPrime(int num)
{
    if (num == 1)
        return false;
    bool result = true;
    for (int i = 2; i < (int)sqrt(num); i++)
    {
        if (num % i == 0)
            result = false;
    }
    return result;
}
void cal()
{
    for (int i = -39; i <= 50; i++)
    {
        int target = i * i + i + 41;
        if (isPrime(target))
            // 使用make_pair构造键值对
            map.insert(make_pair(i, true));
        else
            map.insert(make_pair(i, false));
    }
}

int main()
{
    cal();
    int x, y;
    // 条件特殊处理，省去了结尾的IF判断
    while (scanf("%d%d", &x, &y), x || y)
    {
        bool isAllPrime = true;
        for (int i = x; i <= y; i++)
        {
            // map直接取值
            if (!map[i])
                isAllPrime = false;
        }
        if (isAllPrime)
            cout << "OK" << endl;
        else
            cout << "Sorry" << endl;
    }
    return 0;
}