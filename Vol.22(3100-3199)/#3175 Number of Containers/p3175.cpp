// 1801496 2009-03-24 09:01:08 Accepted  3175 C++ 170 184 呆滞的慢板 

// 算是有点小巧妙的题吧，求 SUM(N div i - 1), i = 1..N。
// 枚举 i，p = N div i，可以得到当前 i 的结果是 p + 1。
// 然后求有同样结果的有多少个，取 t = N / i + 1。
// 那么同样的结果有 (p - 1) * (t - i)，累加起来。
// 然后步进条件改为 i = t 替换掉就行了效率约 O(sqrt(N))。 

#include <iostream>
using namespace std;

int main() {
    int T, N;
    for(cin >> T; T--;) {
        cin >> N;
        long long ans = 0;
        for(int p = 1, q, t; p < N;) {
            q = N / p;
            t = N / q + 1;
            ans += (q - 1) * (t - p);
            p = t;
        }
        cout << ans << endl;
    }
}
