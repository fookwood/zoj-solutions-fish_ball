// 1668621 2008-10-16 10:44:35 Accepted  2068 C++ 260 4116 呆滞的慢板 

// DP，关键在于，排序之后最优的解匹配中必定不存在交叉。 

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long i64;

i64 X[501], Y[501], Z[501];

int N1, N2, T;

i64 DP[501][501], V[501][501];

int main() {
    
    for(cin >> T; T--;) {
        
        cin >> N1;
        for(int i = 0; i < N1; ++i)
            cin >> X[i];
        
        sort(X, X + N1);
        
        cin >> N2;
        for(int j = 0; j < N2; ++j)
            cin >> Y[j];
            
        sort(Y, Y + N2);
        
        if(N1 > N2) {
            memcpy(Z, X, sizeof(i64) * N1);
            memcpy(X, Y, sizeof(i64) * N2);
            memcpy(Y, Z, sizeof(i64) * N1);
            swap(N1, N2);
        }
        
        for(int i = 1; i <= N1; ++i)
            for(int j = 1; j <= N2; ++j)
                V[i][j] = (X[i-1]-Y[j-1])*(X[i-1]-Y[j-1]);

        memset(DP[0], 0, sizeof(DP[0]));
        
        for(int i = 1; i <= N1; ++i) {
            DP[i][i] = DP[i-1][i-1] + V[i][i];
            for(int j = i+1; j <= N2; ++j) {
                DP[i][j] = min (
                    DP[i][j-1], 
                    DP[i-1][j-1] + V[i][j]
                );
            }
        }
        
        cout << DP[N1][N2] << endl;
        
    }
    
}
