// 不难的 1 维 DP，O(n)但是下面的一种情况绝对不能忽略！
// 因为 0 是没有编码的！
// 2866342 2008-04-24 17:07:17 Accepted 2202 C++ 00:00.02 876K 呆滞的慢板 

#include <iostream>
#include <string>
using namespace std;

int main() {
    string  s;
    while( ( cin >> s ) && s != "0" ) {
        int x = 1, y = 1, z;
        for( int i = 1; i < s.size(); i++ ) {
            if( s[i] == '0' ) y = x;
            else if( s[i - 1] == '1' ||
                s[i - 1] == '2' &&
                s[i] <= '6' ) {
                z = x + y;
                x = y;
                y = z;
            }
            else x = y;
        }
        cout << y << endl;
    }
}
