// 1838844 2009-04-20 12:17:10 Accepted  2156 C++ 440 300 呆滞的慢板  

// 非常经典的多重背包问题，具体算法可见背包九讲。注意物品拆分，路径保存和最优性判断。 
 
#include <iostream>
using namespace std;

int P[10001], Q[10001], C[10001];

int N, A[4];

int B[] = {1, 5, 10, 25};

int main() {
    while(cin >> N >> A[0] >> A[1] >> A[2] >> A[3] && N) {
        memset(P, -1, sizeof(P));
        P[0] = 0;
        C[0] = 0;
        for(int i = 0; i < 4; ++i) {
            for(int k = 0, j; A[i]; ++k) {
                if((1<<k) < A[i]) j = 1<<k;
                else j = A[i];
                A[i] -= j;
                for(int v = N; v >= 0; --v) {
                    if(P[v] != -1 && v + B[i] * j <= N) {
                        if(P[v + B[i] * j] == -1 || C[v + B[i] * j] < C[v] + j) {
                            P[v + B[i] * j] = i;
                            Q[v + B[i] * j] = j;
                            C[v + B[i] * j] = C[v] + j;
                        }
                    }
                }
            }
        }
        if(P[N] == -1) {
            puts("Charlie cannot buy coffee.");
        }
        else {
            int C[4] = {};
            int v = N;
            while(v != 0) {
                C[P[v]] += Q[v];
                v -= B[P[v]] * Q[v];
            }
            printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n", C[0], C[1], C[2], C[3]);
        }
    }
}
