#include <iostream>
using namespace std;

int G[20][20], M, N, K, V, C;

// 每列几个 
int R[20];

bool B[20][20];

int calc() {
    int ans = 0;
    memset(B, 0, sizeof(B));
    for(int i = 0, j; i < M; ++i) {
        int beg = -1;
        for(j = 0; j < N; ++j) {
            if()
        }
    }
    return ans;
}

int drop(int k) {
    G[M-++R[k]][k] = V;
}

int take(int k) {
    G[M-R[k]--][k] = -1;
}

int judge() {
    int ans = -1; pos = -1;
    for(int i = 0; i < N; ++i) {
        drop(i);
        int v = calc();
        if(v > ans) { ans = v; pos = i; }
        take(i);
    }
    return pos;
}

void apply(int k) {
    drop(k);
    eliminate();
    push();
}

void eliminate() {
}
    
int main() {
    while(scanf("%d%d", &M, &N, &K) == 3) {
        memset(R, 0, sizeof(R));
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                scanf("%d", &G[i][j]);
                if(G[i][j] != -1 && !R[j]) {
                    R[j] = M - i;
                }
            }
        }
        C = 0;
        while(K--) {
            scanf("%d", &V);
            apply(judge());
        }
        printf("%d\n", C);
    }
}
