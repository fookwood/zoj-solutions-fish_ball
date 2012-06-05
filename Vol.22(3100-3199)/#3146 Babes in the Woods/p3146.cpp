// 1762139 2009-02-13 13:55:34 Accepted  3146 C++ 0 184 呆滞的慢板 

// 常规的最短路，SPFA 很容易写，注意有一点，
// 如果走路的范围要越出外框，那么该方向依然可以走，
// 不过走到地图的边缘就不能继续前进了，但是距离仍然按照那个数字算。

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {

    const int dx[] = {0, 0, 1, -1};
    const int dy[] = {1, -1, 0, 0};

    int M, N, r, c;

    int G[30][30], P[30][30];

    while(cin >> M >> N >> r >> c) {

        for(int i = 0; i < M; ++i)
            for(int j = 0; j < N; ++j)
                cin >> G[i][j];

        memset(P, -1, sizeof(P));

        queue<int> Q;
        P[r - 1][c - 1] = 0;
        Q.push((r - 1) * 30 + c - 1);

        int dist = -1;

        while(!Q.empty()) {
            int x = Q.front() / 30;
            int y = Q.front() % 30;
            int d = P[x][y];
            Q.pop();
            if(G[x][y] == 0)
                if(dist == -1 || dist > d)
                    dist = d;
            for(int k = 0; k < 4; ++k) {
                int nx = x + dx[k] * G[x][y];
                int ny = y + dy[k] * G[x][y];
                nx = max(nx, 0);
                nx = min(nx, M - 1);
                ny = max(ny, 0);
                ny = min(ny, N - 1);
                if(P[nx][ny] == -1 || P[nx][ny] > d + G[x][y]) {
                    P[nx][ny] = d + G[x][y];
                    Q.push(nx * 30 + ny);
                }
            }
        }

        if(dist != -1)
            cout << dist << endl;
        else
            puts("No solution");

    }

}