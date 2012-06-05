// 1842139 2009-04-23 16:44:36 Accepted  3110 C++ 20 308 呆滞的慢板 

// 入门级 dfs，三维的地图，种子填充法。 

#include <iostream>
#include <vector>
using namespace std;

int M, N, K, T = 0;
char G[50][50][51];

int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 0, 1, -1, 0, 0};
int dz[] = {1, -1, 0, 0, 0, 0};

int dfs(int x, int y, int z, char c) {
    int ans = 1;
    G[x][y][z] = '*';
    for(int i = 0; i < 6; ++i) {
        x += dx[i];
        y += dy[i];
        z += dz[i];
        if(x >= 0 && x < M &&
            y >= 0 && y < N &&
            z >= 0 && z < K &&
            G[x][y][z] == c)
            ans += dfs(x, y, z, c);
        z -= dz[i];
        y -= dy[i];
        x -= dx[i];
    }
    return ans;
}

int main() {
    while(cin >> M >> N >> K) {
        if(T++) puts("");
        cout << "Case " << T << ":" << endl;
        for(int i = 0; i < K; ++i)
            for(int j = 0; j < M; ++j)
                for(int k = 0; k < N; ++k)
                    cin >> G[j][k][i];
        for(char c = 'a'; c <= 'd'; ++c) {
            vector<int> v;
            for(int i = 0; i < M; ++i)
                for(int j = 0; j < N; ++j)
                    for(int k = 0; k < K; ++k)
                        if(G[i][j][k] == c)
                            v.push_back(dfs(i, j, k, c));
            sort(v.begin(), v.end());
            if(v.size() != 0) {
                cout << c;
                for(int i = v.size() - 1; i >= 0; --i)
                    cout << ' ' << v[i];
                puts("");
            }
        }
    }
}
