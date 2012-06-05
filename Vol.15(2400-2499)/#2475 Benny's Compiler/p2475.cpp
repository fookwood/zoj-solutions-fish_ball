// 1723455 2008-12-11 11:39:08 Accepted  2475 C++ 0 184 呆滞的慢板 

// 给一个有向图，问一个顶点可达的位置中是否会存在环。
// 先做 Floyd，然后枚举给定的顶点可达的顶点，
// 如果存在另一个顶点使得 G[v][w] == G[w][v]，那么条件成立。
// 注意问题背景，自环是不算的，因此在初始化图的时候要忽略所有自环。 

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int M, N, E;
    bool G[100][100];
    while(scanf("%d", &M) && M >= 0) {
        memset(G, 0, sizeof(G));
        N = 0;
        for(int i = 0; i < M; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            N = max(N, max(x, y));
            if(x != y)
                G[x-1][y-1] = true;
        }
        scanf("%d", &E);
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                for(int k = 0; k < N; ++k)
                    if(G[j][i] && G[i][k])
                        G[j][k] = true;
        bool circle = false;
        for(int v = 0; v < N; ++v)
            if(G[E-1][v])
                for(int w = 0; w < N; ++w)
                    if(G[v][w] && G[w][v])
                        circle = true;
        puts(circle ? "No" : "Yes");
    }
    return EXIT_SUCCESS;
}
