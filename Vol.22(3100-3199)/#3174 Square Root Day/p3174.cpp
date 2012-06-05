// 1801394 2009-03-24 00:48:50 Accepted  3174 C++ 0 184 呆滞的慢板 

// 简单题，求给定年份之间存在多少个月，
// 使得月份的平方等于年份的后两位或者后三位， 
// 直接枚举年月然后判定，计数即可。 

#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T--;) {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        for(int i = x; i <= y; ++i) {
            for(int j = 1; j <= 12; ++j) {
                if(j * j == i % 100 || j * j == i % 1000)
                    ++ans;
            }
        }
        cout << ans << endl;
    }
}
