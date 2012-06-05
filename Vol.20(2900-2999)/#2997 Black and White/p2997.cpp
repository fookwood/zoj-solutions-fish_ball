// 1869870 2009-05-15 01:57:21 Accepted  2997 C++ 10 184 呆滞的慢板 

// 经典的拓扑排序，构造一个长度为 N 的序列，
// 使得序列所有连续 P 个元素之和为正，且所有连续 Q 个元素之和为负。
// 将问题转化，构造这个序列的累加序列，
// 相当于构造一个长度为 N + 1 的序列 S[0..N]，
// 满足 S[i+P] - S[i] > 0 且 S[i+Q] - S[i] < 0。
// 这样的话，可以构造 N+1 顶点的图，
// 将所有 S[i] > S[j] 的关系创建有向边 (i, j) 。
// 那么，将这个图拓扑排序，然后如果有环，则不可构造，
// 否则，其深搜弹出序号本身即可作为 S[i] 的值。 

#include <iostream>
#include <vector>
using namespace std;

int N, P, Q, cnt;

bool B[5000];

int val[5000];

void dfs(int v) {
    B[v] = true;
    if(v + Q <= N && !B[v + Q]) dfs(v + Q);
    if(v - P >= 0 && !B[v - P]) dfs(v - P);
    val[v] = cnt++;
}

int main() {
    while(scanf("%d%d%d", &N, &P, &Q) != EOF) {
        memset(B, 0, N+1);
        cnt = 0;
        for(int v = 0; v <= N; ++v)
            if(!B[v]) dfs(v);
        bool hasloop = false;
        for(int v = 0; v <= N; ++v) {
            if(v + Q <= N && val[v] < val[v + Q]) hasloop = true;
            if(v - P >= 0 && val[v] < val[v - P]) hasloop = true;
        }
        if(hasloop) puts("NO");
        else {
            puts("YES");
            for(int i = 0; i < N; ++i) {
                if(i) putchar(' ');
                printf("%d", val[i+1] - val[i]);
            }
            puts("");
        }
    }
    
}
