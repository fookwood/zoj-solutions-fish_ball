// 1693225 2008-11-08 15:09:28 Accepted  2974 C++ 0 184 呆滞的慢板 

// 倒水，矩阵乘：生成转移矩阵，然后 logN 求幂。注意 k=0 的含义是只倒回自己，
// 不知道的话会 WA。 

#include <iostream>
using namespace std;

struct Mat {
    int SZ;
    double G[20][20];
    Mat() {}
    Mat(int SZ) : SZ(SZ) {memset(G, 0, sizeof(G));}
};

const Mat operator*(const Mat& a, const Mat& b) {
    Mat c(a.SZ);
    for(int i = 0; i < c.SZ; ++i)
        for(int j = 0; j < c.SZ; ++j)
            for(int k = 0; k < c.SZ; ++k)
                c.G[i][j] += a.G[i][k] * b.G[k][j];
    return c;
}

const Mat pow(const Mat& a, int N) {
    if(N == 1) return a;
    Mat c = pow(a, N / 2);
    c = c * c;
    if(N % 2) c = c * a;
    return c;
}

int main() {
    int T, N, M;
    double V[20];
    for(cin >> T; T--;) {
        cin >> N;
        for(int i = 0; i < N; ++i)
            cin >> V[i];
        Mat c(N);
        for(int i = 0, k; i < N; ++i) {
            cin >> k;
            if(k==0) c.G[i][i] = 1;
            else for(int j = 0, p; j < k; ++j) {
                cin >> p;
                c.G[i][p-1] = 1.0 / k;
            }
        }
        cin >> M;
        c = pow(c, M);
        for(int i = 0; i < N; ++i) {
            if(i) putchar(' ');
            double val = 0.0;
            for(int j = 0; j < N; ++j)
                val += V[j] * c.G[j][i];
            printf("%.2lf", val);
        }
        puts("");
    }
}
