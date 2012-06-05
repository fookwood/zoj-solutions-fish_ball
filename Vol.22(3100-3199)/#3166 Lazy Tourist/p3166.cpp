// 1764003 2009-02-15 23:51:26 Accepted  3166 C++ 360 184 呆滞的慢板

// 求一个顶点，经过它最小的最小环最短，直接 Floy 即可。

#include <iostream>
using namespace std;

int main() {
    int G[100][100], N, E;
    int HOTEL[100], C;
    while(cin >> N >> C) {
        for(int i = 0; i < C; ++i) {
            cin >> HOTEL[i];
            HOTEL[i] -= 1;
        }
        memset(G, -1, sizeof(G));
        for(cin >> E; E--;) {
            int x, y, d;
            cin >> x >> y >> d;
            G[x-1][y-1] = d;
        }
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                for(int k = 0; k < N; ++k) {
                    if(G[j][i] != -1 && G[i][k] != -1 &&
                        (G[j][k] == -1 || G[j][k] > G[j][i] + G[i][k])) {
                        G[j][k] = G[j][i] + G[i][k];
                    }
                }
            }
        }
        int best = -1, index = -1;
        for(int i = 0; i < C; ++i) {
            if(G[HOTEL[i]][HOTEL[i]] == -1) continue;
            else if(best == -1 ||
                best > G[HOTEL[i]][HOTEL[i]]) {
                best = G[HOTEL[i]][HOTEL[i]];
                index = i;
            }
        }
        if(index == -1)
            puts("I will nerver go to that city!");
        else cout << HOTEL[index] + 1 << endl;
    }
}
