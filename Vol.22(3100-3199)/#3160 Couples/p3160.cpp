// 1764000 2009-02-15 23:47:57 Accepted  3160 C++ 20 184 呆滞的慢板 

// 给一个序列，某些编号之间如果相邻可以消去，问最多可以消掉多少个。
// 经典 DP，先预处理出从 i 到 j 可以连块消掉的邻接矩阵，然后将这些块串接起来。 

#include <iostream>
using namespace std;

class SpecialRelations {

    int N, E;

    bool G[300][300], CON[301][301];
    
    int P[300];

public:
    
    bool input() {
        if(!(cin >> N >> E)) return false;
        memset(G, 0, sizeof(G));
        for(int i = 0, x, y; i < E; ++i) {
            cin >> x >> y;
            G[x][y] = G[y][x] = true;
        }
        for(int i = 0; i < N; ++i) cin >> P[i];
        return true;
    }
    
    void solve() {
        memset(CON, 0, sizeof(CON));
        for(int i = 0; i <= N; ++i)
            CON[i][i] = true;
        for(int step = 2; step <= N; step += 2) {
            for(int beg = 0; beg + step <= N; ++ beg) {
                int end = beg + step;
                if(G[P[beg]][P[end - 1]] && CON[beg + 1][end - 1])
                    CON[beg][end] = true;
                for(int d = 2; d < step; d += 2) {
                    int pos = beg + d;
                    if(CON[beg][pos] && CON[pos][end])
                        CON[beg][end] = true;
                }
            }
        }

        int DP[301] = {};
        
        for(int i = 0; i < N; ++i) {
            DP[i + 1] = max(DP[i], DP[i + 1]);
            for(int j = i + 2; j <= N; j += 2)
                if(CON[i][j])
                    DP[j] = max(DP[j], DP[i] + j - i);
        }
        
        cout << DP[N] << endl;
        
    }

};

int main() {
    
    SpecialRelations obj;
    
    while(obj.input()) obj.solve();
}
