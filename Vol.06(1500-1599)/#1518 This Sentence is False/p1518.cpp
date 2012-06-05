// 1665663 2008-10-13 22:50:46 Accepted  1518 C++ 0 212 呆滞的慢板 

// 转化成一个图二着色问题，每句话是一个顶点：
// 如果第 i 句话说第 j 句话是真的，增加一条同色边（双向边）；
// 如果第 i 句话说第 j 句话是假的，增加一条反色边（双向边）。 
// 然后 dfs 染色，如果有染色矛盾，也就是矛盾；
// 否则，对于同一个连通分量，两种颜色的顶点数分别为 X 和 Y。
// 则最终结果增加 max(X, Y)。 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, X, Y;

int C[1001];

vector<int> S[1001], D[1001];

char s[20];

bool dfs(int v, int c) {
    C[v] = c;
    (c == 1 ? X : Y) += 1;
    for(int i = 0, w; i < S[v].size(); ++i) {
        w = S[v][i];
        if(C[w] == 3 - c) return false;
        if(C[w] == 0 && !dfs(w, c)) return false;
    }
    for(int i = 0, w; i < D[v].size(); ++i) {
        w = D[v][i];
        if(C[w] == c) return false;
        if(C[w] == 0 && !dfs(w, 3 - c)) return false;
    }
    return true;
}

int main() {
    while(scanf("%d", &N) && N) {
        for(int i = 1; i <= N; ++i) {
            S[i].clear();
            D[i].clear();
        }
        for(int i = 1; i <= N; ++i) {
            scanf("%s%d%s%s", s, &X, s, s);
            if(*s == 't') {
                S[i].push_back(X);
                S[X].push_back(i);
            }
            else {
                D[i].push_back(X);
                D[X].push_back(i);
            }
        }
        memset(C, 0, sizeof(C));
        bool yes = true;
        int ans = 0;
        for(int i = 1; i <= N; ++i) {
            if(C[i] == 0) {
                X = Y = 0;
                if(!dfs(i, 1)) {
                    yes = false;
                    break;
                }
                ans += max(X, Y);
            }
        }
        if(!yes) puts("Inconsistent");
        else printf("%d\n", ans);
    }
}
