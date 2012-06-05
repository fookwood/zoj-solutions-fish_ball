// 1664877 2008-10-12 23:26:04 Accepted  1802 C++ 0 184 呆滞的慢板 

// 平面图着色，贪心就可以过，连回溯都没，可是算法正确性无法证明。 

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double X[12], Y[12];
int N;
bool G[12][12], K[12];
int C[12], tot, mn;

bool near(int i, int j) {
    return sqrt((X[i]-X[j])*(X[i]-X[j]) +
        (Y[i]-Y[j])*(Y[i]-Y[j])) < 20.0000001;
}

void dfs(int v) {
    bool B[12] = {};
    for(int i = 0; i < N; ++i)
        if(G[v][i])
            B[C[i]] = true;
    for(int c = 1; c <= tot; ++c) {
        if(!B[c]) {
            C[v] = c;
            for(int i = 0; i < N; ++i)
                if(G[v][i] && !C[i])
                    dfs(i);
            return;
        }
    }
    C[v] = ++tot;
    for(int i = 0; i < N; ++i)
        if(G[v][i] && !C[i])
            dfs(i);
}

int main() {
    int T = 1;
    while(cin >> N && N) {
        for(int i = 0; i < N; ++i)
            cin >> X[i] >> Y[i];
        memset(G, 0, sizeof(G));
        for(int i = 0; i < N; ++i)
            for(int j = i + 1; j < N; ++j)
                G[i][j] = G[j][i] = near(i, j);
        tot = 0;
        memset(C, 0, sizeof(C));
        for(int i = 0; i < N; ++i)
            if(!C[i]) dfs(i);
        printf("The towers in case %d can be"
            " covered in %d frequencies.\n", T++, tot);
    }
}
