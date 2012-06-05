// 2002887 2009-09-26 13:04:45 Accepted  1675 C++ 0 188 呆滞的慢板 
// 推箱子模拟，只有一个箱子，求最小推的次数。
// 因此可以直接用广搜，但是状态点应该是推箱前坐标和推箱后坐标组合而成。
// 这样就可以用一个简洁的状态记录人的位置了。 

#include <iostream>
#include <queue>
using namespace std;

int M, N;
bool G[7][7];
bool B[7*7*7*7];

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct Status {
    int bit, step;
    Status(int b) : bit(b), step(0) {}
    Status(int xx1, int yy1, int xx2, int yy2) 
        : bit((((xx1 * 7 + yy1) * 7) + xx2) * 7 + yy2), step(0) {}
    int xc() { return bit / 7 / 7 / 7; }
    int yc() { return bit / 7 / 7 % 7; }
    int xp() { return bit / 7 % 7; }
    int yp() { return bit % 7; }
};

void Search(int xc, int yc, int xp, int yp, queue<Status> &Q, int st) {
    bool X[7][7];
    memcpy(X, G, sizeof(X));
    queue<int> QQ;
    X[xp][yp] = true;
    QQ.push(xp * 7 + yp);
    while(!QQ.empty()) {
        int x = QQ.front() / 7
            , y = QQ.front() % 7;
        QQ.pop();
        for(int d = 0; d < 4; ++d) {
            int xx = x + dx[d];
            int yy = y + dy[d];
            if(xx < 0 || yy < 0 || xx >= M || yy >= N || X[xx][yy]) continue;
            if(xx == xc && yy == yc) {
                xx += dx[d];
                yy += dy[d];
                if(xx < 0 || yy < 0 || xx >= M || yy >= N || G[xx][yy]) continue;
                int s = (((xx * 7 + yy) * 7) + xc) * 7 + yc;
                if(!B[s]) {
                    B[s] = true;
                    Status ss(s);
                    ss.step = st + 1;
                    Q.push(ss);
                }
            }
            else {
                X[xx][yy] = true;
                QQ.push(xx * 7 + yy);
            }
        }
    }
}

int main() {
    while(cin >> N >> M && M) {
        int xc, yc, xg, yg, xp, yp;
        memset(G, 0, sizeof(G));
        memset(B, 0, sizeof(B));
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                int t;
                cin >> t;
                switch(t) {
                    case 0:
                        break;
                    case 1:
                        G[i][j] = true;
                        break;
                    case 2:
                        xc = i;
                        yc = j;
                        break;
                    case 3:
                        xg = i;
                        yg = j;
                        break;
                    case 4:
                        xp = i;
                        yp = j;
                        break;
                    default:
                        break;
                }
            }
        }
        queue<Status> Q;
        Search(xc, yc, xp, yp, Q, 0);
        while(!Q.empty()) {
            Status s = Q.front();
            if(s.xc() == xg && s.yc() == yg) {
                cout << s.step << endl;
                break;
            }
//printf("Q[%d]:(%d,%d)->(%d,%d)\n",s.step, s.xp(),s.yp(),s.xc(),s.yc());
            Q.pop();
            Search(s.xc(), s.yc(), s.xp(), s.yp(), Q, s.step);
        }
        if(Q.empty()) puts("-1");
    }
}
