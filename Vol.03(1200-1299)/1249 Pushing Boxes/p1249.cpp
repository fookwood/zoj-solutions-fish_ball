#include <iostream>
#include <string>
#include <deque>
using namespace std;

enum Direction {
    UP = 0,
    LEFT = 1,
    DOWN = 2,
    RIGHT = 3,
    BACK = 4,
    NIL = -1
};

int DIR[4][2] = {
    {-1, 0
    },
    { 0, -1
    },
    { 1, 0
    },
    { 0, 1
    },
};

struct Record {
    int dir, mov, stp;
    string path;
};

struct Status {
    int x, y, dir;
};

int T = 1, M, N;

int xT, yT, xS, yS, xB, yB;

char G[20][21];

Record R[20][21][4];

inline bool inside(int x, int y) {
    return x >= 0 && y >= 0 &&
            x < M && y < N;
}

void relax(Status s) {
    char P[20][21];
    int D[20][20];
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            P[i][j] = G[i][j];
            G[i][j] = NIL;
        }
    }
    deque<pair<int, int> > Q;
    int x = s.x - DIR[s.dir][0],
            y = s.y - DIR[s.dir][1];
    Q.push_back(make_pair(x, y));
    D[x][y] = BACK;
    P[x][y] = '#';
    P[s.x][s.y] = '#';
    while (!Q.empty()) {
        x = Q.front().first;
        y = Q.front().second;
        Q.pop_front();
        for (int i = 0; i < 4; ++i) {
            x += DIR[i][0];
            y += DIR[i][1];
            if (inside(x, y) && P[x][y] != '#') {
                P[x][y] = '#';
                D[x][y] = i;
                Q.push_back(make_pair(x, y));
            }
            x -= DIR[i][0];
            y -= DIR[i][1];
        }
    }
}

void input() {
    for (int i = 0; i < M; ++i) {
        cin >> G[i];
        for (int j = 0; j < N; ++j) {
            if (G[i][j] == 'T') {
                G[i][j] = '.';
                xT = i;
                yT = j;
            }
            if (G[i][j] == 'S') {
                G[i][j] = '.';
                xS = i;
                yS = j;
            }
            if (G[i][j] == 'B') {
                G[i][j] = '.';
                xB = i;
                yB = j;
            }
        }
    }
}

int main() {

    while (cin >> M >> N) {

        input();

        

    }

}
