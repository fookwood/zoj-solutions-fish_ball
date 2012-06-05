// 1661548 2008-10-09 13:00:37 Accepted  1903 C++ 10 312 呆滞的慢板 

// 中国邮路问题，Floyd + 一般图匹配(状态压缩DP解决)。 

#include <iostream>
#include <algorithm>
using namespace std;

int N, M, tot;
int DP[1<<15], G[15][15], deg[15];

const int INF = INT_MAX/2;

int main() {
    while(cin >> N && N) {
        cin >> M;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                G[i][j] = INF;
        memset(deg, 0, sizeof(deg));
        tot = 0;
        for(int i = 0; i < M; ++i) {
            int x, y, d;
            cin >> x >> y >> d;
            ++deg[x-1];
            ++deg[y-1];
            G[x-1][y-1] = G[y-1][x-1] = 
                min(G[x-1][y-1], d);
            tot += d;
        }
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                for(int k = 0; k < N; ++k)
                    G[j][k] = min(G[j][k], G[j][i] + G[i][k]);
        for(int i = 0; i < 1<<N; ++i)
            DP[i] = INF;
        DP[0] = 0;
        int final = 0;
        for(int i = 0; i < N; ++i) {
            if(deg[i] % 2 == 1) {
                final |= (1<<i);
                for(int j = i+1; j < N; ++j) {
                    if(deg[j] % 2 == 1) {
                        int bit = (1<<i) + (1<<j);
                        for(int k = 0; k < 1<<N; ++k)
                            if((k&bit) == 0 && DP[k] != INF)
                                DP[k|bit] = min(DP[k|bit], DP[k] + G[i][j]);
                    }
                }
            }
        }
        tot += DP[final];
        cout << tot << endl;
    }
}
