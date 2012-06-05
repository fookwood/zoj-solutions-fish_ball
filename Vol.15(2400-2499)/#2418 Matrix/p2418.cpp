// 1683777 2008-10-31 00:44:09 Accepted  2418 C++ 330 184 呆滞的慢板 

// 要枚举所有行的不同移位方案的组合，最多 n^n 种，但是要剪枝：
// 1. 第一行可以不动，总是移位 0；
// 2. 再求值的时候增加分支限界，当某一列总和大于现有结果，直接 break； 
 

#include <iostream>
#include <algorithm>
using namespace std;

int N, P[7], A[7][7], ans;

void dfs(int k) {
    int tot = 0;
    for(int i = 0; i < N; ++i) {
        int val = 0;
        for(int j = 0; j < N; ++j)
            val += A[j][(i+P[j])%N];
        tot = max(tot, val);
        if(tot > ans) break;
    }
    ans = min(ans, tot);
    if(P[k] + 1 < N) {
        P[k] += 1;
        dfs(k);
        P[k] -= 1;
    }
    if(k + 1< N) dfs(k+1);
}

int main() {
    while(cin >> N && N != -1) {
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                cin >> A[i][j];
        memset(P, 0, sizeof(P));
        ans = INT_MAX;
        dfs(1);
        cout << ans << endl;
    }
}
