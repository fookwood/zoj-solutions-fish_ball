// 1837996 2009-04-19 11:21:20 Accepted  2134 C++ 950 184 呆滞的慢板 

// 求最大割，本来就是 NP 问题，直接蛮力之后还有仔细优化一下常数才行。 

#include <iostream>
using namespace std;

int main() {
    int T, N, A[20][20];
    int S[20], tp;
    for(cin >> T; T--;) {
        cin >> N;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                cin >> A[i][j];
        int best = 0;
        for(int mask = 0; mask < (1<<N); ++mask) {
            int now = 0;
            tp = 0;
            for(int i = 0; i < N; ++i)
                if(mask&(1<<i))
                    S[tp++] = i;
            for(int i = 0; i < N; ++i) {
                if(mask&(1<<i)) continue;
                for(int j = 0; j < tp; ++j)
                    now += A[i][S[j]];
            }
            if(now > best) best = now;
        }
        cout << best << endl;
        if(T) puts("");
    }
}
