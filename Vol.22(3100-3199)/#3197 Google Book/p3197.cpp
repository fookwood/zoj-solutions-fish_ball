// 1863326 2009-05-10 18:44:24 Accepted  3197 C++ 60 184 呆滞的慢板 

// 给出若干个线段，求把整个 [0,N] 的区间覆盖需要最少多少条线段。 
// 比较特殊的贪心方法，先对所有区间排序。
// 然后，顺序枚举，记录到当前区间左界止最少的次数 K，初始化 K 为 1。 
// 和 K-1 次时能到达最右位置 A，以及新一段往后接能到最右的位置 B。
// 对于当前枚举到的线段，如果左界 > A+1，那么 A = B，并 K++ 
// 然后用其右区间更新到 B。

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T, N;
    for(scanf("%d", &T); T--;) {
        scanf("%d", &N);
        pair<short, short> S[5000];
        for(int i = 0, x, y; i < N; ++i)
            scanf("%d%d", &S[i].first, &S[i].second);
        sort(S, S + N);
        short A = 0, B = 0, K = 1;
        for(int i = 0; i < N; ++i) {
            if(S[i].first > A + 1) {
                A = B;
                K++;
            }
            B = max(B, S[i].second);
            if(B == N) break;
        }
        printf("%d\n", K);
    }
}
