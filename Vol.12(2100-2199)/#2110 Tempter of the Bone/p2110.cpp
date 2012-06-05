#include <iostream>
#include <set>
using namespace std;

char A[7][8];
int M, N, T, sx, sy, tx, ty;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

bool dfs(int x, int y, int t) {
    if(abs(tx-x) + abs(ty-y) == 0 && t == 0) return true;
    if(abs(tx-x) + abs(ty-y) > t) return false;
    for(int d = 0; d < 4; ++d) {
        x += dx[d];
        y += dy[d];
        if(x >= 0 && x < M && y >= 0 && y < N && A[x][y] != 'X') {
            A[x][y] = 'X';
            if(dfs(x, y, t-1))
                return true;
            A[x][y] = '.';
        }
        x -= dx[d];
        y -= dy[d];
    }
    return false;
}

int main() {

    while(cin >> M >> N >> T && M) {

        for(int i = 0; i < M; ++i) {
            cin >> A[i];
            for(int j = 0; j < N; ++j) {
                if(A[i][j] == 'S') {
                    sx = i;
                    sy = j;
                    A[i][j] = 'X';
                }
                if(A[i][j] == 'D') {
                    tx = i;
                    ty = j;
                }
            }
        }
        if((T^(abs(sx-tx)+abs(sy-ty)))&1) {
            puts("NO");
            continue;
        }
        puts(dfs(sx, sy, T) ? "YES" : "NO");
    }
}
