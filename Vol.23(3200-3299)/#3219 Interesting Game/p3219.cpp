// 1914705 2009-07-11 10:48:47 Accepted  3219 C++ 10 264 呆滞的慢板 

// 经典的高斯消元，根据概率转移建立线性方程组，再消元求解。
// 状态一共 A+B+1 种，假设 X(K) 是 javaman 拿着 K 个苹果时赢的概率，
// 那么，有 p 的概率转移到 X(K-C) 这个状态，
// 有 1-p 的概率转移到 X(K+D) 这个状态，
// 明显对于所有 K>A+B，有 X(K) = 1，
// 而对于 K<0 或者，必有 X(K) = 0。 
// 因此可以列出方程：X(K) = p * X(K-C) + (1-p) * X(K+D)
// 再手动判别一下 K-C 和 K+D，如果 > A+B 或者 < 0 换成常数
// 由此即可构造线性方程组矩阵，从而消元求解。 

#include <iostream>
#include <algorithm> 
#include <cmath>
using namespace std;

/*
TEST CASES:
    
100
5 5 3 2 0.6
5 5 6 4 0.6
5 5 2 4 0.6
5 5 1 0 0.6
5 5 0 1 0.6

*/

const int MAXN = 100;
const double EPS = 1e-10; 

int T, A, B, C, D, N;

double G[MAXN][MAXN+1];

double p;

// 高斯消元法解 K*K+1 方程组矩阵。 
bool Gaussian_Elimination(double M[][MAXN+1], int K) {
    // 下三角消元 
    for(int r = 0; r < K; ++r) {
        // 如果列主元系数为零 
        if(-EPS <= M[r][r] && M[r][r] < EPS) {
            // 执行行调换
            int idx = -1;
            for(int r2 = r + 1; r2 < K && idx == -1; ++r2)
                if(M[r2][r] < -EPS || M[r2][r] >= EPS)
                    idx = r2;
            // 如果全列为零，返回无解 
            if(idx == -1) return false; 
            // 否则，执行行调换 
            for(int c = r; c <= K; ++c)
                swap(M[r][c], M[idx][c]);
        }
        // 本行归一化
        for(int c = K; c >= r; --c)
            M[r][c] /= M[r][r];
        // 本列下方清零 
        for(int c = K; c >= r; --c)
            for(int r2 = r + 1; r2 < K; ++r2)
                M[r2][c] = M[r2][c] - M[r][c] * M[r2][r];
    }
    // 上三角消元
    for(int r = K - 1; r >= 0; --r) {
        for(int r2 = r - 1; r2 >= 0; --r2) {
            M[r2][K] -= M[r][K] * M[r2][r];
            M[r2][r] -= M[r2][r];
        }
    } 
    return true;
}

int main() {
    for(cin >> T; T--;) {
        scanf("%d%d%d%d%lf", &A, &B, &C, &D, &p);
        N = A + B + 1;
        memset(G, 0, sizeof(G));
        for(int X = 0; X <= A + B; ++X) {
            G[X][X] = 1; 
            if(X + D > A + B)
                G[X][A+B+1] += 1-p;
            else
                G[X][X+D] += p-1;
            if(X >= C)
                G[X][X-C] += -p;
        }
        if(!Gaussian_Elimination(G, A+B+1))
            while(1) puts("OLE!!");
        printf("%.2lf\n", G[A][A+B+1]);
    }
}
