#include <cstdio>

// 反面的标号 
const int INV[6] = { 5, 3, 4, 1, 2, 0 };

int P[10000][6], I[10000][6];
int T,  N,  mx, tot;

int main() {

    for(scanf("%d", &T); T--;) {

        scanf("%d", &N);
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < 6; ++j) {
                scanf("%d", &P[i][j]);
                I[i][P[i][j] - 1] = j;
            }
        }

        mx = 0;
        
        for(int d = 0, b = P[0][d], idx; d < 6; ++d) {
            tot = 0;
            for(int i = 0; i < N; ++i) {
                idx = I[i][b-1];
                int now = 0;
                for(int j = 0; j < 6; ++j)
                    if(j != idx && j != INV[idx] && now < P[i][j])
                        now = P[i][j];
                tot += now;
                b = P[i][INV[idx]];
            }
            if(tot > mx) mx = tot;
        }
        
        printf("%d\n", mx); 
    
    } 
    
}
