#include <bitset>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    cout << "35的8进制:" << oct << 35 << endl;
    cout << "35的10进制" << dec << 35 << endl;
    cout << "35的16进制:" << setiosflags(ios::uppercase) << hex << 3666 << endl;
    cout << "35的2进制: " << bitset<8>(35) << endl; //<8>：表示保留8位输出
    return 0;
}