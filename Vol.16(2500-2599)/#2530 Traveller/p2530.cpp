// 1655790 2008-10-04 10:21:20 Accepted  2531 C++ 30 444 呆滞的慢板 

// 格雷码的生成，dfs 即可。 

#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<bool> B;
vector<int> V;

bool dfs(int k) {
    B[k] = true;
    V.push_back(k);
    if(V.size() == N) return true;
    for(int i = 1; i < N; i <<= 1)
        if(!B[i^k] && dfs(i^k))
            return true;
    return false;
}

int main() {
    while(scanf("%d%d", &N, &K) && N) {
        B.assign(N, false);
        V.clear();
        dfs(K);
        for(int i = 0; i < N; ++i) {
            if(i) putchar(' ');
            printf("%d", V[i]);
        }
        puts("");
    }
}
