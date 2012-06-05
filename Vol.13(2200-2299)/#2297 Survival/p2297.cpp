// 1662858 2008-10-10 20:02:40 Accepted  2297 C++ 440 4280 呆滞的慢板 

// 状态压缩 DP，可以将 n! 的状态压缩到 2^n. 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, H;
int C[20], R[20];
int DP[1<<20];
bool B[20];

void set(int bit) {
    memset(B, 0, sizeof(B));
    for(int i = 1; i <= bit; ++i)
        B[N-i] = true;
}

int get() {
    int ans = 0;
    for(int i = 0; i < N; ++i) {
        ans <<= 1;
        ans += B[i];
    }
    return ans;
}

int main() {
    while(cin >> N) {
        N -= 1;
        for(int i = 0; i < N; ++i)
            cin >> C[i] >> R[i];
        cin >> H;
        memset(DP, -1, sizeof(DP));
        DP[0] = 100;
        for(int i = 0, bit; i < N; ++i) {
            set(i);
            do {
                bit = get();
                if(DP[bit] == -1) continue;
                for(int j = 0; j < N; ++j) {
                    if((bit&(1<<j)) == 0 && DP[bit] >= C[j]) {
                        DP[bit|(1<<j)] = max(DP[bit|(1<<j)], DP[bit]-C[j]+R[j]);
                        DP[bit|(1<<j)] = min(DP[bit|(1<<j)], 100);
                    }
                }
            } while(next_permutation(B, B+N));
        }
        puts(DP[(1<<N)-1] >= H ? "clear!!!" : "try again");
    }
}
