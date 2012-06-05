// 1831968 2009-04-13 11:58:10 Accepted  2098 C++ 0 184 呆滞的慢板 

// 很简单的组合概率计算，结果 = Prod(C(M[i], P[i])) / C(M, K)。 

#include <iostream>
using namespace std;

int main() {
    
    double C[51][51] = {};
    C[0][0] = 1;
    for(int i = 0; i < 50; ++i) {
        for(int j = 0; j <= i; ++j) {
            C[i+1][j] += C[i][j];
            C[i+1][j+1] += C[i][j];
        }
    }
    
    int N, K, R;
    int M[50], P[50];
    while(cin >> N >> K && N != -1) {
        R = 0;
        for(int i = 0; i < N; ++i) {
            cin >> M[i];
            R += M[i];
        }
        for(int i = 0; i < N; ++i)
            cin >> P[i];
        double ans = 1.0;
        for(int i = 0; i < N; ++i)
            ans *= C[M[i]][P[i]];
        ans /= C[R][K];
        printf("%.5lf\n", ans);
    }
    
}
