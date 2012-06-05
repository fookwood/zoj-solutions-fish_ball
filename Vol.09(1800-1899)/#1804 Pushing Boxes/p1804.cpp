// 1651224 2008-09-29 00:13:57 Accepted  1804 C++ 0 268 呆滞的慢板 

// 模拟题，注意读题，如果出现位置不够，推土机会被顶停。 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int R, C, K, N, x, y, T = 1;

string op;

bool G[20][20];
int RN, CN;

vector<int> V;

int main() {
    
    while(cin >> R >> C && R) {
        cin >> N;
        memset(G, 0, sizeof(G));
        for(int i = 0; i < N; ++i) {
            cin >> x >> y;
            G[x][y] = true;
        }
        while(cin >> op && op != "done") {
            cin >> K;
            RN = CN = 0;
            for(int i = 0; i < R; ++i) {
                int cc = 0;
                for(int j = 0; j < C; ++j)
                    if(G[i][j])
                        ++cc;
                CN = max(CN, cc);
            }
            for(int j = 0; j < C; ++j) {
                int rr = 0;
                for(int i = 0; i < R; ++i)
                    if(G[i][j])
                        ++rr;
                RN = max(RN, rr);
            }
            if(op == "up") {
                if(R - K < RN) K = R - RN;
                for(y = 0; y < C; ++y) {
                    V.clear();
                    for(int x = R-1; x >= 0; --x) {
                        if(G[x][y]) {
                            G[x][y] = false;
                            V.push_back(x);
                            V.back() = min(V.back(), R - K - 1);
                        }
                    }
                    for(int i = 1; i < V.size(); ++i)
                        if(V[i] >= V[i-1])
                            V[i] = V[i-1] - 1;
                    for(int i = 0; i < V.size(); ++i)
                        G[V[i]][y] = true;
                }
            }
            else if(op == "down") {
                if(R - K < RN) K = R - RN;
                for(y = 0; y < C; ++y) {
                    V.clear();
                    for(int x = 0; x < R; ++x) {
                        if(G[x][y]) {
                            G[x][y] = false;
                            V.push_back(x);
                            V.back() = max(V.back(), K);
                        }
                    }
                    for(int i = 1; i < V.size(); ++i)
                        if(V[i] <= V[i-1])
                            V[i] = V[i-1] + 1;
                    for(int i = 0; i < V.size(); ++i)
                        G[V[i]][y] = true;
                }
            }
            else if(op == "left") {
                if(C - K < CN) K = C - CN;
                for(x = 0; x < R; ++x) {
                    V.clear();
                    for(int y = C-1; y >= 0; --y) {
                        if(G[x][y]) {
                            G[x][y] = false;
                            V.push_back(y);
                            V.back() = min(V.back(), C - K - 1);
                        }
                    }
                    for(int i = 1; i < V.size(); ++i)
                        if(V[i] >= V[i-1])
                            V[i] = V[i-1] - 1;
                    for(int i = 0; i < V.size(); ++i)
                        G[x][V[i]] = true;
                }
            }
            else if(op == "right") {
                if(C - K < CN) K = C - CN;
                for(x = 0; x < R; ++x) {
                    V.clear();
                    for(int y = 0; y < C; ++y) {
                        if(G[x][y]) {
                            G[x][y] = false;
                            V.push_back(y);
                            V.back() = max(V.back(), K);
                        }
                    }
                    for(int i = 1; i < V.size(); ++i)
                        if(V[i] <= V[i-1])
                            V[i] = V[i-1] + 1;
                    for(int i = 0; i < V.size(); ++i)
                        G[x][V[i]] = true;
                }
            }
        }
        printf("Data set %d ends with boxes at locations", T++);
        for(x = 0; x < R; ++x) {
            for(y = 0; y < C; ++y) {
                if(G[x][y])
                    printf(" (%d,%d)", x, y);
            }
        }
        puts(".");
    }
    
} 
