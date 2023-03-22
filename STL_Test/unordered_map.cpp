#include <unordered_map>
#include <iostream>
using namespace std;

int main()
{
    unordered_map<int, bool> map;
    map.insert(make_pair(1, true));
    map.insert(make_pair(-1, false));
    cout << map[1] << map[-1];
    return 0;
}