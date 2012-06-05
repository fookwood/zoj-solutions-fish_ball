// 1788597 2009-03-14 14:13:12 Accepted  3094 C++ 2010 9316 呆滞的慢板 

// 敢死队，很经典的一道题，二分 + BFS。 
// 首先需要做一个预处理，处理出每一个格子离最近的敌营的距离： 
// 这可以通过对所有敌营入队列 BFS 得出。
// 然后二分一个最近距离，这个结果应该处于 0 到 X + Y 之间。 
// 对于二分的每一个值 bound，从起点 (xi, yi) BFS 到终点 (xr, yr)。
// 可走的点为所有到敌营距离 >= bound 的格子。
// 如果对某个 bound 不通，改小它，否则改大它，这样就可以二分了。 

#include <iostream>
#include <queue>
using namespace std;

int T, N, X, Y, xi, yi, xr, yr;
int G[1000][1000];
int P[1000][1000];

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

// 检查如果保持距离 >= bound 的情况下的最短路，不通返回 -1 
// P[][] 表示到达某个位置的最短路长度 
int checkAtBound(int bound) {
    if(G[xi][yi] < bound) return -1;
    memset(P, -1, sizeof(P));
    queue<pair<int, int> > Q;
    P[xi][yi] = 0;
    Q.push(make_pair(xi, yi));
    while(!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        int l = P[x][y];
        if(x == xr && y == yr) break;
        Q.pop();
        for(int d = 0; d < 4; ++d) {
            x += dx[d];
            y += dy[d];
            if(x >= 0 && x < X && y >= 0 && y < Y &&
                P[x][y] == -1 && G[x][y] >= bound) {
                P[x][y] = l + 1;
                Q.push(make_pair(x, y));
            }
            x -= dx[d];
            y -= dy[d];
        }
    }
    return P[xr][yr];
}

int main() {
    for(cin >> T; T--;) {
        cin >> N >> X >> Y;
        cin >> xi >> yi >> xr >> yr;
        
        // G[][] 表示地图上任一点到达最近的敌营的距离
        // 通过多源最短路(此处为直接 BFS)求得 
        memset(G, -1, sizeof(G));
        queue<pair<int, int> > Q;
        for(int i = 0, x, y; i < N; ++i) {
            scanf("%d%d", &x, &y);
            G[x][y] = 0;
            Q.push(make_pair(x, y));
        }
        while(!Q.empty()) {
            int x = Q.front().first;
            int y = Q.front().second;
            int l = G[x][y];
            Q.pop();
            for(int d = 0; d < 4; ++d) {
                x += dx[d];
                y += dy[d];
                if(x >= 0 && x < X && y >= 0 && y < Y && G[x][y] == -1) {
                    G[x][y] = l + 1;
                    Q.push(make_pair(x, y));
                }
                x -= dx[d];
                y -= dy[d];
            }
        }
                
        int r = X + Y, l = 0, m, len;
        while(r > l + 1) {
            m = r + l >> 1;
            if(checkAtBound(m) == -1) r = m;
            else l = m;
        }
        cout << l << ' ' << checkAtBound(l) << endl;
    }
}
