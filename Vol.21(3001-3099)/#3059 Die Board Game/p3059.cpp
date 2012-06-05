// 2047 2008-11-09 15:31:31 Accepted  D C++ 140 1600 呆滞的慢板 

// 1694339 2008-11-09 17:39:21 Accepted  3059 C++ 120 1600 呆滞的慢板 

// 广搜，关键在于骰子状态的表示，用 top 和 north 的排列作为状态即可。
// 可以预处理出各个状态向四面滚能够到达的状态，然后 BFS 即可。 

#include <deque>
#include <iostream>
using namespace std;

int M, N;

char G[100][101];
int DP[100][100][36];

int C[4][36];
bool B[50];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int base[6], target[6];
int sx, sy, tx, ty;

bool fail;

void gen(int b[6]) {
    if(b[0] == target[0] && b[2] == target[2])
        for(int i = 0; i < 6; ++i)
            if(b[i] != target[i])
                fail = true;
    int a[6];
    int now = b[0] * 6 + b[2];
    B[now] = true;
    if(C[0][now] == -1) {
        a[0] = b[4]; a[1] = b[5]; a[2] = b[2];
        a[3] = b[3]; a[4] = b[1]; a[5] = b[0];
        C[0][now] = a[0] * 6 + a[2];
        if(!B[a[0] * 6 + a[2]])
            gen(a);
    }
    if(C[1][now] == -1) {
        a[0] = b[5]; a[1] = b[4]; a[2] = b[2];
        a[3] = b[3]; a[4] = b[0]; a[5] = b[1];
        C[1][now] = a[0] * 6 + a[2];
        if(!B[a[0] * 6 + a[2]])
            gen(a);
    }
    if(C[2][now] == -1) {
        a[0] = b[2]; a[1] = b[3]; a[2] = b[1];
        a[3] = b[0]; a[4] = b[4]; a[5] = b[5];
        C[2][now] = a[0] * 6 + a[2];
        if(!B[a[0] * 6 + a[2]])
            gen(a);
    }
    if(C[3][now] == -1) {
        a[0] = b[3]; a[1] = b[2]; a[2] = b[0];
        a[3] = b[1]; a[4] = b[4]; a[5] = b[5];
        C[3][now] = a[0] * 6 + a[2];
        if(!B[a[0] * 6 + a[2]])
            gen(a);
    }
}

struct Status{
    int x, y, s, d;
    Status() {}
    Status(int x, int y, int s, int d) :
        x(x), y(y), s(s), d(d) {}
};

deque<Status> Q;

int main() {
    while(cin >> M >> N) {
        for(int i = 0; i < M; ++i)
            cin >> G[i];
        cin >> sx >> sy >> tx >> ty;
        for(int i = 0; i < 6; ++i) {
            cin >> base[i];
            base[i] -= 1;
        }
        for(int i = 0; i < 6; ++i) {
            cin >> target[i];
            target[i] -= 1;
        }

        memset(C, -1, sizeof(C));
        memset(B, 0, sizeof(B));
        fail = false;
        gen(base);
        
        if(fail == true) {
            puts("-1");
            continue;
        }

        Q.clear();
        memset(DP, -1, sizeof(DP));

        DP[sx][sy][base[0] * 6 + base[2]] = 0;
        Q.push_back(Status(sx, sy, base[0] * 6 + base[2], 0));

        Status now;
        while(!Q.empty()) {
            now = Q.front();
            if(now.x == tx && now.y == ty &&
                now.s == target[0] * 6 + target[2]) break;
            Q.pop_front();
            int x = now.x, y = now.y, s = now.s, d = now.d;
            for(int i = 0; i < 4; ++i) {
                x += dx[i];
                y += dy[i];
                int ns = C[i][s];
                if(x >= 0 && x < M && y >= 0 && y < N
                    && G[x][y] == '.' && DP[x][y][ns] == -1) {
                    DP[x][y][ns] = d + 1;
                    Q.push_back(Status(x, y, ns, d+1));
                }
                x -= dx[i];
                y -= dy[i];
            }
        }

        if(Q.empty()) puts("-1");
        else cout << now.d << endl;
    }
}
