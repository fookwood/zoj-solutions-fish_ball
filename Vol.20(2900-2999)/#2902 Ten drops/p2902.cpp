// 1693557 2008-11-08 18:57:32 Accepted  2902 C++ 0 184 呆滞的慢板 

// 十滴水小游戏，用个任务队列乱搞即可。
// 注意空格中或者玩家水箱中没水时，操作要忽略。 

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int N, D, B, C, T = 0;

int G[20][20];

struct Drop {
    int x, y, dx, dy;
    Drop() {}
    Drop(int x, int y, int dx, int dy) :
        x(x), y(y), dx(dx), dy(dy) {}
    Drop& inc() {x += dx; y += dy; return *this;}
    int dir() const {
        if(dx == 1 && dy == 0) return 1;
        if(dx == -1 && dy == 0) return 2;
        if(dx == 0 && dy == 1) return 3;
        if(dx == 0 && y == -1) return 4;
        return 0;
    }
    bool outside() {
        return x < 0 || y < 0 || x == N || y == N;
    }
};

deque<Drop> Q[4];

int main() {
    while(cin >> N >> D >> B >> C) {
        if(T++) puts("");
        memset(G, 0, sizeof(G));
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                char c;
                cin >> c;
                G[i][j] = c - '0';
            }
        }
        while(C--) {
            int x, y;
            cin >> x >> y;
            if(G[x][y] == 0) continue;
            if(D == 0) continue;
            else D--;
            if(++G[x][y] < B) continue;
            G[x][y] = 0;
            Q[0].clear();
            Q[1].clear();
            Q[2].clear();
            Q[3].clear();
            Q[0].push_back(Drop(x, y, 1, 0));
            Q[1].push_back(Drop(x, y, -1, 0));
            Q[2].push_back(Drop(x, y, 0, 1));
            Q[3].push_back(Drop(x, y, 0, -1));
            Q[0].push_back(Drop(-1, 0, 0, 0));
            Q[1].push_back(Drop(-1, 0, 0, 0));
            Q[2].push_back(Drop(-1, 0, 0, 0));
            Q[3].push_back(Drop(-1, 0, 0, 0));
            while(Q[0].front().x >= 0 || Q[1].front().x >= 0 ||
                Q[2].front().x >= 0 || Q[3].front().x >= 0) {
                for(int i = 0; i < 4; ++i) {
                    while(Q[i].front().x >= 0) {
                        Drop now = Q[i].front().inc();
                        x = now.x;
                        y = now.y;
                        Q[i].pop_front();
                        if(now.outside()) continue;
                        if(G[x][y] == 0) {
                            Q[i].push_back(now);
                            continue;
                        }
                        if(++G[x][y] == B) {
                            G[x][y] = 0;
                            Q[0].push_back(Drop(x, y, 1, 0));
                            Q[1].push_back(Drop(x, y, -1, 0));
                            Q[2].push_back(Drop(x, y, 0, 1));
                            Q[3].push_back(Drop(x, y, 0, -1));
                        }
                    }
                }
                for(int i = 0; i < 4; ++i) {
                    Q[i].push_back(Q[i].front());
                    Q[i].pop_front();
                }
            }
        }
        cout << D << endl;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j)
                putchar(G[i][j] + '0');
            cout << endl;
        }
    }
}
