#include <iostream>
using namespace std;

typedef long long i64;

i64 P[100][100];
i64 C[100];
i64 x[100];

const i64 MOD = 1000000007;

// N 是多项式项数，M 是向量维度。 
int T, N, M, Q;

i64 pow(int i, int n) {
    if(n == 0) return 1;
    i64 v = pow(x[i], n >> 1);
    v *= v;
    v %= MOD;
    if(n & 1) return (v * x[i]) % MOD;
    else return v;
}

i64 IN[100][100], OUT[100][100];

void init() {
    for(int i = 0; i < N; ++i) {
        IN[i][0] = 1;
        for(int j = 0; j < M; ++j) {
            IN[i][0] *=
        }
    }
}

i64 eval(int i) {
    i64 ans = 0;
    for(int n = 0; n < N; ++n) {
        if(P[n][i] == 0) continue;
        i64 c = C[n];
        if(c == 0) continue;
        for(int j = 0; j < M; ++j) {
            if(j == i) continue;
            c *= pow(j, P[n][j]);
            c %= MOD;
        }
        c *= P[n][i];
        c %= MOD;
        c *= pow(i, P[n][i] - 1);
        c %= MOD;
        ans += c;
        ans %= MOD;
    }
    return ans;
}

int main() {
    
    for(scanf("%d", &T); T--;) {
        
        scanf("%d%d", &N, &M);
        for(int i = 0; i < N; ++i) {
            scanf("%d", C + i);
            for(int j = 0; j < M; ++j)
                scanf("%d", P[i] + j);
        }

        for(scanf("%d", &Q); Q--;) {
            for(int p = 0; p < M; ++p)
                scanf("%d", x + p);
            for(int p = 0; p < M; ++p) {
                if(p) putchar(' ');
                cout << eval(p);
            }
            puts("");
        }
        
        if(T) puts("");
    }
}
