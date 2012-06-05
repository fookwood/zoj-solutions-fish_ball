// 2056422 2009-12-13 18:06:00 Accepted  3278 C++ 1000 1748 呆滞的慢板 

// 求两个数组的交叉积里面的第 K 大数。
// 双重二分，先做一个二分函数，给定一个值，知道 <= 它的有多少个。
// 然后做外层的二分，二分结果，从小到大找到第一个值 val，使得 <= val 的值有 M*N-K+1 个。
// 整体复杂度为 O(M*log(N)*log(MAXVAL))。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long a[100000], b[100000];
long long M, N, K;

long long check(long long val) {
    long long cnt = 0;
    for(int i = M-1; i >= 0; --i) {
        if(a[i] * b[N-1] <= val) {
            return cnt + N * (i + 1);
        }
        else if(a[i] * b[0] > val) {
            continue;
        }
        else {
            int l = 0, r = N, m;
            while(r != l + 1) {
                m = (l + r) / 2;
                if(a[i] * b[m] <= val) {
                    l = m;
                }
                else {
                    r = m;
                }
            }
            cnt += r;
        }
    }
    return cnt;
}

int main() {
    while(scanf("%I64d%I64d%I64d", &M, &N, &K) != EOF) {
        for(int i = 0; i < M; ++i) {
            scanf("%I64d", a + i);
        }
        sort(a, a + M);
        for(int i = 0; i < N; ++i) {
            scanf("%I64d", b + i);
        }
        sort(b, b + N);
        long long l = a[0] * b[0] - 1, r = a[M-1] * b[N-1], m;
        K = M * N - K + 1;
        while(r != l + 1) {
            m = (l + r) / 2;
            if(check(m) < K) {
                l = m;
            }
            else {
                r = m;
            }
        }
        cout << r << endl;
    }
}
