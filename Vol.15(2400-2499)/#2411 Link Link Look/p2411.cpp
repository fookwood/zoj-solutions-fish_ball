// 1682836 2008-10-30 14:22:44 Accepted  2411 C++ 330 236 呆滞的慢板 

// 连连看，有限步数连通，BFS 即可。 

#include <iostream>
#include <queue>
using namespace std;

int G[102][102], M, N, K;
bool B[102][102];

struct Rec {
    int x, y, k;
    Rec() {}
    Rec(int x, int y, int k) :
        x(x), y(y), k(k) {}
};

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

inline bool valid(int x, int y) {
    return x >= 0 && x <= N + 1 &&
           y >= 0 && y <= M + 1;
}

int main() {
    
    while(scanf("%d%d", &N, &M) && M) {
        memset(G, 0, sizeof(G));
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= M; ++j)
                scanf("%d", &G[i][j]);
        int tot = 0, x1, x2, y1, y2;
        for(scanf("%d", &K); K--;) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if(G[x1][y1] == 0 || G[x1][y1] != G[x2][y2])
                continue;
            queue<Rec> Q;
            memset(B, 0, sizeof(B));
            Q.push(Rec(x1, y1, 0));
            B[x1][y1] = true;
            bool found = false;
            while(!Q.empty()) {
                int x = Q.front().x;
                int y = Q.front().y;
                int k = Q.front().k;
                Q.pop();
                for(int d = 0; d < 4; ++d) {
                    int t = 1, nx, ny;
                    while(valid(nx = x+t*dx[d], ny = y+t*dy[d])) {
                        if(G[nx][ny] == 0) {
                            if(k < 2 && !B[nx][ny]) {
                                Q.push(Rec(nx, ny, k+1));
                                B[nx][ny] = true;
                            }
                        }
                        else {
                            if(nx == x2 && ny == y2)
                                found = true;
                            break;
                        }
                        t += 1;
                    }
                    if(found) break;
                }
                if(found) break;
            }
            if(found) {
                G[x1][y1] = G[x2][y2] = 0;
                tot += 2;
            }
        }
        printf("%d\n", tot);
    }
    
}
