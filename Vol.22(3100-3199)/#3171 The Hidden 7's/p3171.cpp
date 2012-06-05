// 1773753 2009-03-01 15:36:49 Accepted  3171 C++ 20 184 呆滞的慢板 

// 给一个字符串，问里边不同的子序列是 'seven' 的有多少个。
// 很经典很巧妙的 DP 题，O(n) 的时间空间就可以解决。

#include <string>
#include <iostream>
using namespace std;

int main() {
    string s;
    while(cin >> s) {
        long long cnt[5] = {};
        for(int i = 0; i < s.size(); ++i) {
            s[i] = tolower(s[i]);
            if(s[i] == 's') cnt[0]++;
            if(s[i] == 'e') cnt[1] += cnt[0];
            if(s[i] == 'v') cnt[2] += cnt[1];
            if(s[i] == 'e') cnt[3] += cnt[2];
            if(s[i] == 'n') cnt[4] += cnt[3];
        }
        cout << cnt[4] << endl;
    }
}
