// 1665708 2008-10-13 23:55:46 Accepted  1505 C++ 5680 7988 呆滞的慢板 

// 跳棋，状态压缩广搜，时间差不多，应该刚刚好的。 

#include <iostream>
#include <deque>
#include <set>
using namespace std;

typedef long long Pos;

bool C[8][8], *D = C[0];

Pos pack() {
    Pos x = 0;
    for(int i = 0; i < 64; ++i) {
        x <<= 1;
        x += D[i];
    }
    return x;
}

void unpack(Pos x) {
    for(int i = 63; i >= 0; --i) {
        D[i] = x & 1;
        x >>= 1;
    }
}

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

inline bool isValid(int x, int y) {
    return x >= 0 && y >= 0 &&
        x < 8 && y < 8;
}

int main() {
    
    set<Pos> S;
    
    while(true) {
        Pos begin, end;
        memset(C, 0, sizeof(C));
        for(int i = 0, x, y; i < 4; ++i) {
            if(!(cin >> x >> y)) return EXIT_SUCCESS;
            C[x-1][y-1] = true;
        }
        begin = pack();
        memset(C, 0, sizeof(C));
        for(int i = 0, x, y; i < 4; ++i) {
            cin >> x >> y;
            C[x-1][y-1] = true;
        }
        end = pack();
        deque<pair<Pos, int> > Q(1, make_pair(begin, 0));
        S.clear();
        S.insert(begin);
        bool found = false;
        while(!Q.empty()) {
            Pos now = Q.front().first;
            if(now == end) {
                found = true;
                break;
            }
            int k = Q.front().second;
            if(k > 8) break;
            Q.pop_front();
            unpack(now);
            for(int x = 0, x1, x2; x < 8; ++x) {
                for(int y = 0, y1, y2; y < 8; ++y) {
                    if(!C[x][y]) continue;
                    for(int d = 0; d < 4; ++d) {
                        x1 = x + dx[d];
                        y1 = y + dy[d];
                        if(isValid(x1, y1) && !C[x1][y1]) {
                            C[x][y] = false;
                            C[x1][y1] = true;
                            now = pack();
                            if(S.find(now) == S.end()) {
                                S.insert(now);
                                Q.push_back(make_pair(now, k+1));
                            }
                            C[x1][y1] = false;
                            C[x][y] = true;
                        }
                        x2 = x1 + dx[d];
                        y2 = y1 + dy[d];
                        if(isValid(x2, y2) && !C[x2][y2] && C[x1][y1]) {
                            C[x][y] = false;
                            C[x2][y2] = true;
                            now = pack();
                            if(S.find(now) == S.end()) {
                                S.insert(now);
                                Q.push_back(make_pair(now, k+1));
                            }
                            C[x2][y2] = false;
                            C[x][y] = true;
                        }
                    }
                }
            }
        }
        puts(found ? "YES" : "NO");
    }
    
}
