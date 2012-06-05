#include <cstdio>
#include <cstring>

int N, cnt = 0;

short P[3001];

short find(short x) {
    if(P[x] == x) return x;
    return P[x] = find(P[x]);
}

int main() {
    
    memset(P, -1, sizeof(P));

    scanf("%d", &N);
    
    for(int i = 1, x; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            scanf("%d", &x);
            if(x) {
                if(P[j]) P[find(j)] = j;
                if(P[j-1]) P[j-1] = j;
                P[j] = j;
            }
            else {
                if(P[j] = j) ++cnt;
                P[j] = 0;
            }
        }
    }
    
    printf("%d\n", cnt);
    
}
