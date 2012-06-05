// 1654078 2008-10-02 17:59:04 Accepted  2505 C++ 20 304 呆滞的慢板 

// 数据结构题，使用类似并查集的数据结构：并查区间来动态维护连续区间。 
 
#include <cstdio>

bool B[4096];
int P[4096];
int S[4096];

inline int max(int x, int y) {return x > y ? x : y;}

int T, N, MX, K;

int check(int x) {
    if(P[x] == x) return x;
    return P[x] = check(P[x]);
}

void turn_on(int x) {
    B[x] = true;
    if(x < 4095 && B[x+1]) {
        P[x+1] = x;
        S[x] = S[x+1] + 1;
    }
    else S[x] = 1;
    if(x > 0 && B[x-1]) {
        P[x] = P[x-1];
        S[check(x)] += S[x];
    }
    MX = max(MX, S[check(x)]);
}

void turn_off(int x) {
    B[x] = false;
    int y = x + 1, p = check(x);
    while(y < 4096 && B[y] && check(y) == p) y++;
    if(B[x+1]) S[x+1] = y - x - 1;
    for(int i = x + 1; i < y; ++i) P[i] = x + 1;
    S[p] -= y - x;
    P[x] = x;
}

int main() {
    for(scanf("%d", &T); T--;) {
        MX = 1;
        for(int i = 0; i < 4096; ++i) {
            B[i] = false;
            P[i] = i;
        }
        for(scanf("%d", &N); N--;) {
            scanf("%d", &K);
            if(B[K-1]) turn_off(K-1);
            else turn_on(K-1);
        }
        printf("%d\n", MX);
    }
}
