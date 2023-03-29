#include <vector>
#include <iostream>
using namespace std;

void func1(vector<int> vec)
{
    cout << vec[0];
}
void func2(vector<int> &vec)
{
    cout << vec[0];
}
void func3(vector<int> *vec)
{
    cout << (*vec)[0];
}

int main()
{
    vector<int> list;
    // 值传递(常用)
    func1(list);
    // 引用传递(常用)
    func2(list);
    // 地址传递
    func3(&list);
    return 0;
}