// 1656643 2008-10-04 19:16:16 Accepted  3048 C++ 30 184 ´ôÖÍµÄÂý°å 

#include <iostream>
using namespace std;

int M, N, S, K;
char G[20][21];
int P[20][20];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int dfs(int x, int y) {
    int ans = 1;
    char c = G[x][y];
    P[x][y] = K;
    for(int i = 0; i < 4; ++i) {
        x += dx[i];
        y += dy[i];
        if(x >= 0 && x < M &&
            y >= 0 && y < N &&
            !P[x][y] && G[x][y] == c)
            ans += dfs(x, y);
        y -= dy[i];
        x -= dx[i];
    }
    return ans;
}

bool kill() {
    memset(P, 0, sizeof(P));
    K = 1;
    int mk, cn = 1;
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            if(G[i][j] && !P[i][j]) {
                int p = dfs(i, j);
                if(p > cn) {
                    mk = K;
                    cn = p;
                }
                K++;
            }
        }
    }
    if(cn == 1) return false;
    for(int i = 0; i < M; ++i)
        for(int j = 0; j < N; ++j)
            if(P[i][j] == mk)
                G[i][j] = 0;
    S += cn * (cn - 1);
    return true;
}

void recover() {
    for(int j = 0; j < N; ++j) {
        for(int i = M-1, n = M-1; i >= 0; --i) {
            if(!G[i][j]) continue;
            char p = G[i][j];
            G[i][j] = 0;
            G[n--][j] = p;
        }
    }
    for(int j=0, n=0; j < N; ++j) {
        if(!G[M-1][j]) continue;
        for(int i = 0; i < M; ++i) {
            char p = G[i][j];
            G[i][j] = 0;
            G[i][n] = p;
        }
        n++;
    }
}

int main() {
    while(cin >> M >> N) {
        for(int i = 0; i < M; ++i)
            cin >> G[i];
        S = 0;
        while(kill()) recover();
        cout << S << endl;
    }
}
