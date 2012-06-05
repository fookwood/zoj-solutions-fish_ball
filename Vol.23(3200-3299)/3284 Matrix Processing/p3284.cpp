#include <iostream>
using namespace std;

int A[100][100], R[100], C[100], M, N, Q;

int main(){
    int T = 0;
    while(scanf("%d%d", &M, &N) != EOF) {
        printf("Case %d\n", ++T);
        memset(A, 0, sizeof(A));
        memset(R, 0, sizeof(R));
        memset(C, 0, sizeof(C));
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                scanf("%d", A[i] + j);
            }
        }
        scanf("%d", &Q);
        while(Q--) {
            int op, x1, y1, x2, y2, v;
            scanf("%d", &op);
            if(op == 0) {
                scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &v);
                --x1;
                --y1;
                --x2;
                --y2;
                if(y1 == y2) {
                    if(x2 < x1) swap(x2, x1);
                    for(int i = x1; i <= x2; ++i) {
                        A[i][y1] += v;
                    }
                }
                else {
                    if(y2 < y1) {
                        swap(x1, x2);
                        swap(y1, y2);
                    }
                    for(int j = y1; j < N; ++j) {
                        A[x1][j] += v;
                    }
                    for(int i = x1 + 1; i < x2; ++i) {
                        R[i] += v;
                    }
                    for(int j = 0; j <= y2; ++j) {
                        A[x2][j] += v;
                    }
                }
            }
            else if(op == 1) {
                scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &v);
                --x1;
                --y1;
                --x2;
                --y2;
                if(x1 == x2) {
                    if(y2 < y1) swap(y2, y1);
                    for(int j = y1; j <= y2; ++j) {
                        A[x1][j] += v;
                    }
                }
                else {
                    if(x2 < x1) {
                        swap(x1, x2);
                        swap(y1, y2);
                    }
                    for(int i = x1; i < M; ++i) {
                        A[i][y1] += v;
                    }
                    for(int j = y1+1; j < y2; ++j) {
                        C[j] += v;
                    }
                    for(int i = 0; i <= x2; ++i) {
                        A[i][y2] += v;
                    }
                }
            }
            else if(op == 2) {
                scanf("%d%d", &x1, &y1);
                printf("%d\n", A[x1-1][y1-1] + R[x1-1] + C[y1-1]);
            }
            else {
                while(1) puts("exception 001");
            }
        }
    }
}
