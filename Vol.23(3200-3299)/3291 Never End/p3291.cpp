#include <iostream>
#include <queue>
using namespace std;

char G[500][500];
int M, N;

bool B[4*500*500];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

bool valid(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N
        && G[x][y] != '#';
}

void drop(int& x, int& y, int d) {
    while(valid(x+dx[d], y+dy[d])) {
        x += dx[d];
        y += dy[d];
    }
}

inline int enc(int x, int y, int d) {
    return 500 * (500 * d + x) + y;
}

inline void dec(int& x, int& y, int& d, int code){
    y = code % 500;
    x = (code / 500) % 500;
    d = code / 250000;
}

bool left(int& x, int& y, int d) {
    int dd = (d+3)%4;
    int xx = x + dx[dd], yy = y + dy[dd];
    if(valid(xx, yy)) {
        x = xx, y = yy;
        drop(x, y, d);
        return !B[enc(x, y, d)];
    }
    else {
        return false;
    }
}

bool right(int& x, int& y, int d) {
    int dd = (d+1)%4;
    int xx = x + dx[dd], yy = y + dy[dd];
    if(valid(xx, yy)) {
        x = xx, y = yy;
        drop(x, y, d);
        return !B[enc(x, y, d)];
    }
    else {
        return false;
    }
}

bool rotl(int& x, int& y, int& d) {
    d = (d+3)%4;
    drop(x, y, d);
    return !B[enc(x, y, d)];
}

bool rotr(int& x, int& y, int& d) {
    d = (d+1)%4;
    drop(x, y, d);
    return !B[enc(x, y, d)];
}

int main() {
    int x, y, d, ex, ey;
    while(cin >> M >> N >> ws) {
        for(int i = 0; i < M; ++i) {
            gets(G[i]);
            d = 0;
            for(int j = 0; j < N; ++j) {
                if(G[i][j] == '|') {
                    x = i;
                    y = j;
                }
                else if(G[i][j] == 'E') {
                    ex = i;
                    ey = j;
                }
            }
        }
        queue<pair<int, int> > Q;
        memset(B, 0, sizeof(B));
        int now = enc(x, y, d);
        B[now] = true;
        Q.push(make_pair(now, 0));
        int ans = -1;
        while(!Q.empty()) {
            dec(x, y, d, Q.front().first);
            if(left(x, y, d)) {
                int cd = enc(x, y, d);
                B[cd] = true;
                Q.push(make_pair(cd, Q.front().second + 1));
                if(x == ex && y == ey) {
                    ans = Q.front().second + 1;
                    break;
                }
            }
            dec(x, y, d, Q.front().first);
            if(right(x, y, d)) {
                int cd = enc(x, y, d);
                B[cd] = true;
                Q.push(make_pair(cd, Q.front().second + 1));
                if(x == ex && y == ey) {
                    ans = Q.front().second + 1;
                    break;
                }
            }
            dec(x, y, d, Q.front().first);
            if(rotl(x, y, d)) {
                int cd = enc(x, y, d);
                B[cd] = true;
                Q.push(make_pair(cd, Q.front().second + 1));
                if(x == ex && y == ey) {
                    ans = Q.front().second + 1;
                    break;
                }
            }
            dec(x, y, d, Q.front().first);
            if(rotr(x, y, d)) {
                int cd = enc(x, y, d);
                B[cd] = true;
                Q.push(make_pair(cd, Q.front().second + 1));
                if(x == ex && y == ey) {
                    ans = Q.front().second + 1;
                    break;
                }
            }
            Q.pop();
        }
        if(ans == -1) {
            puts("Can not escape!");
        }
        else {
            cout << ans << endl;
        }
    }
}
